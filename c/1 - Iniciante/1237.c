/*
	Yuri Niitsuma <ignitzhjfk@gmail.com>
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG

// Códigos retirados do livro "Projeto em Algoritmos"
// Nivio Ziviani
// Procedimento de pesquisa utilizando Boyer Moore Horspool Sunday
int BMHS(char *T, long n, char *P, long m)
{
	long i, j, k, d[256 + 1];
	for (j = 0; j <= 256; j++)
		d[j] = m + 1;
	for (j = 1; j <= m; j++)
		d[P[j-1]] = m - j + 1;

	i = m;
	while(i <= n)
	{
		k = i;
		j = m;
		
		while(T[k-1] == P[j-1] && j > 0)
		{
			k--; j--;
		}
		
		if (j == 0)
			return 1;
		i += d[T[i]];
	}
	return 0;
}

int main()
{
	char 	string_entrada[100],
			string_sub[100],
			*string_temp;
	long n, m;

	while(gets(string_entrada) != NULL && gets(string_sub) != NULL)
	{		
		n = 0,
		m = 0;
		while(n <= 50 && string_entrada[n] != '\0')
			n++;

		while(m <= 50 && string_sub[m] != '\0')
			m++;

		#ifdef DEBUG
		puts(string_entrada);
		puts(string_sub);
		printf("%d %d %d %d\n", n, m, strlen(string_entrada), strlen(string_sub));
		#endif

		long 	i, j,
				flag = 0;

		for (j = 0; j < m; j++)
		{
			for (i = 0; i <= j; i++)
			{
				string_temp = (char*) malloc(m - j + 1);
				strncpy(string_temp, string_sub + i, m - j);	
				string_temp[m - j] = '\0';

				#ifdef DEBUG
				printf("%s e %d\n", string_temp, m-j);
				#endif

				if(BMHS(string_entrada, n, string_temp, m-j))
				{
					printf("%d\n", m-j);
					flag = 1;
					break;
				}
				free(string_temp);
			}
			if (flag == 1)
				break;
		}

		if (flag == 0)
			printf("0\n");
	}
	return 0;
}
