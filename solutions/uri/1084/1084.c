#include <stdio.h>

int main(int argc, char const *argv[])
{
	int 	D, N, iNew_Number;
	char	sNumber[100001],
			sTemp[100001];
	int 	count,
			New_Size;

	while(scanf("%d %d", &N, &D) == 2 && D < N)
	{
		scanf("%s", sNumber);
		
		iNew_Number = N - D;

		New_Size = 0;

		for (count = 0; count < N; ++count)
			sTemp[count] = 0;

		for (count = 0; count < N; ++count)
		{
			while(D > 0 && sNumber[count] > sTemp[New_Size-1] && New_Size != 0)
			{
				New_Size--;
				D--;
			}

			if (New_Size < iNew_Number)
			{
				sTemp[New_Size] = sNumber[count];
				New_Size++;
			}
		}
		sTemp[New_Size] = '\0';
		printf("%s\n", sTemp);

	}
	return 0;
}