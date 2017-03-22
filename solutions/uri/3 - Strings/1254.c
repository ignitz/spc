/*
URI - Substituição de Tag (1254)
Yuri Niitsuma <ignitzhjfk@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Força Bruta do slide da aula modificada para o problema
char *ForcaBruta(char *T, long n, char *P, long m)
{
    char *bReplaceFlag = malloc(51*sizeof(char));
    int bFlag = 0;
    long i , j , k;

    for (i = 0; i < strlen(T); i++)
        bReplaceFlag[i] = 0;

    for ( i = 1; i <= (n - m + 1) ; i++)
    {
        if(T[i-1] == '<')
            bFlag = 1;
        if(T[i-1] == '>')
            bFlag = 0;

        k = i ; j = 1;
        while ( (
            (T[k-1] == P[j-1]) ||
            (T[k-1] == P[j-1] + 32) ||
            (T[k-1] == P[j-1] - 32) )
            && j <= m && bFlag == 1)
        {
            j++; k++;
        }
        if ( j > m)
        {
            bReplaceFlag[i-1] = 1;
            i += m - 1;
        }
    }
    return bReplaceFlag;
}

int main()
{
    char    *sPadrao = malloc(11*sizeof(char)),
            *sReplace = malloc(5*sizeof(char)),
            *sTexto = malloc(51*sizeof(char)),
            *sAns = malloc(251*sizeof(char));

    char    *bReplaceFlag;
    long    i, k;

    while(gets(sPadrao) != NULL && gets(sReplace) != NULL)
    {   
        gets(sTexto);

        bReplaceFlag = ForcaBruta(sTexto, strlen(sTexto), sPadrao, strlen(sPadrao));
        
        i = 0; k=0;
        while(i < strlen(sTexto))
        {
            if (bReplaceFlag[i] == 1)
            {
                strcpy(sAns + k, sReplace);
                //puts(sAns);
                k += strlen(sReplace);
                i += strlen(sPadrao);
            }
            else
            {
                sAns[k++] = sTexto[i++];
                //puts(sAns);
            }
        }
        sAns[k] = '\0';
        puts(sAns);
        free(bReplaceFlag);
        free(sPadrao);
        free(sReplace);
        free(sTexto);
        free(sAns);
        sPadrao =  (char*) malloc(11*sizeof(char));
        sReplace = (char*) malloc(5*sizeof(char));
        sTexto =   (char*) malloc(51*sizeof(char));
        sAns =     (char*) malloc(251*sizeof(char));
    }
    return 0;
}