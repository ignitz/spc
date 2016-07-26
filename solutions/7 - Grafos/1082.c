#include <stdio.h>
#include <stdlib.h>

void printGrafo(int *V, unsigned long int iNumVert)
{
	unsigned long int i, j, k; // Counters

	int iCount = 0;

	char temp;

	int flag = 0,
		*check;
	check = (int*) malloc(iNumVert * sizeof(int));
	
	for (i = 0; i < iNumVert; ++i)
		check[i] = 0;
	

	for (i = 0; i < iNumVert; ++i)
	{
		for (j = i; j < iNumVert; ++j)
		{
			if (check[j] == 0 && V[j] == i)
			{
				flag = 1;
				check[j] = 1;
				printf("%c,", (char) j + 97);
			}	
		}
		if(flag)
		{
			printf("\n");
			flag = 0;
			iCount++;
		}
	}

	free(check);
	printf("%d connected components\n\n", iCount);
	return;
}

printState(int *V, unsigned long int iNumVert)
{
	unsigned long int i;
	for (i = 0; i < iNumVert; ++i)
	{
		printf("%d ", V[i]);
	}
	printf("\n");
	return;
}

int main(int argc, char const *argv[])
{
	unsigned long int 	iNumCase,
						iNumVert, // [1, 26] OR [0,25]
						iNumEdge,
						i, j, k; // Counters

	int V[26];
	int a, b, temp, tico, teco;

	char cVert_1, cVert_2;

	scanf("%lu\n", &iNumCase);
	// printf("%lu\n", iNumCase);

	for (i = 0; i < iNumCase && !feof(stdin); ++i)
	{
		printf("Case #%lu:\n", i + 1);
		scanf("%lu %lu\n", &iNumVert, &iNumEdge);
		// printf("%lu %lu\n", iNumVert, iNumEdge);

		for (k = 0; k < iNumVert; ++k) // Definir conjuntos disjuntos
		{
			V[k] = k;
			// printf("%c ", (char) V[k] + 97);
		}
		//printf("\n");

		for (j = 0; j < iNumEdge; ++j)
		{
			scanf("%c %c\n", &cVert_1, &cVert_2);
			//printf("%c %c\n", cVert_1, cVert_2);

			a = (int) cVert_1 - 97;
			b = (int) cVert_2 - 97;

			if (V[a] != V[b])
			{
				//printf("%d %d %d\n", V[a], a, V[b], b);
				if (V[a] < V[b])
					temp = V[a];
				else
					temp = V[b];

				tico = V[a];
				teco = V[b];

				for (k = 0; k < iNumVert; ++k) // União dos conjuntos
					if (V[k] == tico || V[k] == teco)
						V[k] = temp;

				//printState(V, iNumVert);
			}
		}
		printGrafo(V, iNumVert);
	}
	return 0;
}