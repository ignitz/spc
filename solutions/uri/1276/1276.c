#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 0x61 97 ==== a
// 0x7a 122 ==== z

void putsIntervalo(char *bFlag)
{
	char bVirgula = 0;

	int i = 0;
	while(i <= 25)
	{
		if (bFlag[i])
		{
			if (bVirgula)
			{
				printf(", %c:", i + 0x61);
				while(bFlag[i] && i <=25)
					i++;
				printf("%c", i - 1 + 0x61);
			}
			else
			{
				printf("%c:", i + 0x61);
				while(bFlag[i] && i <=25)
					i++;
				printf("%c", i - 1 + 0x61);
			}
			bVirgula = 1;
		}
		i++;
	}
	printf("\n");
	return;
}

int main(int argc, char const *argv[])
{
	char 	sEntrada[51],
			bFlag[0x7a - 0x61 + 2];

	int 	i, n;

	while(gets(sEntrada) != NULL)
	{
		n = strlen(sEntrada);
		for (i = 0; i <= 25 ; ++i)
			bFlag[i] = 0;

		i = 0;
		while(i < n)
		{
			if (sEntrada[i] != ' ')
				bFlag[sEntrada[i] - 0x61] = 1;
			i++;
		}

		putsIntervalo(bFlag);
		// for (i = 0; i <= 26 ; ++i)
		// 	printf("%c = %d\n", 0x61 + i, bFlag[i]);
		// puts(sEntrada);
	}
	return 0;
}
