#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
// #define DEBUG
 
/*
000xxxxx   STA x   armazena o valor do acumulador no byte x da memória
001xxxxx   LDA x   carrega o valor do byte x da memória para o acumulador
010xxxxx   BEQ x   se o valor do acumulador for 0, carregue o valor x para o contador de programa
011-----   NOP     nenhuma operação
100-----   DEC     subtraia 1 do acumulador
101-----   INC     adicione 1 ao acumulador
110xxxxx   JMP x   carregue o valor de x para o contador de programa
111-----   HLT     finaliza o programa
*/
 
unsigned char convertBin2Int(char *value)
{
    unsigned char   n = 0,
    i;
 
    for (i = 1; i <= strlen(value); ++i)
    {
        if (value[i-1] == '1')
        {
            n += pow(2, strlen(value) - i);
        }
    }
    //printf("n = %d\n", n);
    return n;
}
 
void printBin(unsigned char n)
{
    unsigned char temp;
    unsigned char   i = 0;
    for (i = 1; i <= 8; ++i)
    {
        temp = n >> 8-i;
        if (!(temp % 2))
            printf("0");
        else
            printf("1");
    }
    return;
}
 
int exec()
{
    unsigned char   i,
                    accu,
                    mem[32],
                    pc,
                    temp;
 
    do{
        pc = accu = 0;
        i = 0;
        while(i < 32){
            char instruction[9];
            scanf("%s", instruction); //printf("%s\n", instruction);
            mem[i] = convertBin2Int(instruction);
            // printf("%d\n", mem[i]);
            if (feof(stdin))
                break;
            i++;
        }
        // 000xxxxx   STA x   armazena o valor do acumulador no byte x da memória
        // 001xxxxx   LDA x   carrega o valor do byte x da memória para o acumulador
        // 010xxxxx   BEQ x   se o valor do acumulador for 0, carregue o valor x para o contador de programa
        // 011-----   NOP     nenhuma operação
        // 100-----   DEC     subtraia 1 do acumulador
        // 101-----   INC     adicione 1 ao acumulador
        // 110xxxxx   JMP x   carregue o valor de x para o contador de programa
        // 111-----   HLT     finaliza o programa
 
        while(1)
        {
			if (feof(stdin))
         	   break;

            temp = mem[pc];
            pc++;
            if (pc >= 32)
            {
                pc = 0;
            }
             
            // 000xxxxx   STA x   armazena o valor do acumulador no byte x da memória
            if (temp >> 5 == 0)
                mem[temp] = accu;
            // 001xxxxx   LDA x   carrega o valor do byte x da memória para o acumulador
            if (temp >> 5 == 1)
                accu = mem[temp % 32];
            // 010xxxxx   BEQ x   se o valor do acumulador for 0, carregue o valor x para o contador de programa
            if (temp >> 5 == 2)
                if (accu == 0)
                    pc = temp % 32;
            // 011-----   NOP     nenhuma operação
            if (temp >> 5 == 3)
            {
                // do nothing
            }
            // 100-----   DEC     subtraia 1 do acumulador
            if (temp >> 5 == 4)
                accu--;
            // 101-----   INC     adicione 1 ao acumulador
            if (temp >> 5 == 5)
                accu++;
            // 110xxxxx   JMP x   carregue o valor de x para o contador de programa
            if (temp >> 5 == 6)
                pc = temp % 32;
            // 111-----   HLT     finaliza o programa
            if (temp >> 5 == 7)
            {
                printBin(accu);
                if (!feof(stdin))
                    printf("\n");
                break;
            }
        }
 
        if (feof(stdin))
            break;
    }while(1);
    return 0;
}
 
 
int main(int argc, char const *argv[])
{
    exec();
    return 0;
}
