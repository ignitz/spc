#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <windows.h>
// #include <sys/time.h>

typedef struct Person
{
	int x;
	int y;
}Person;

typedef struct Aresta
{
	double dist;
	int i;
	int j;
}Aresta;

double CalcDist (int Ax, int Ay, int Bx, int By)
{
	return sqrt((double)((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By)));
}

void quickSort(Aresta *buffer, int iLeft, int iRight)
{
    int i, j;
    Aresta Aux, x;
    i = iLeft;
    j = iRight;
    x = *(buffer + (iLeft + iRight) / 2);
 
    while(i <= j)
    {
        while((buffer + i)->dist < x.dist && i < iRight)
        {
        	i++;
        }

        while( (buffer + j)->dist > x.dist && i < iRight)
        {
        	j--;
        }

        if(i <= j)
        {
            Aux = *(buffer + i);
            *(buffer + i) = *(buffer + j);
            *(buffer + j) = Aux;
            i++;
            j--;
        }
    }
    if(j > iLeft)
    {
        quickSort(buffer, iLeft, j);
    }
    if(i < iRight)
    {
        quickSort(buffer,  i, iRight);
    }
}

void PrintGrafo(Aresta *Grafo, int iN)
{
	int i;
	for (i = 0; i < iN; ++i)
	{
		printf("%d %d %f\n", (Grafo + i)->i,(Grafo + i)->j,(Grafo + i)->dist);
	}
}

void DistMin(Aresta *Grafo, int iNumCoord, int *Node_check)
{
	unsigned long int i;
	double iTotal = 0;

	for (i = 0; i < iNumCoord; ++i)
	{
		Node_check[i] = i;
	}

	i = 0;
	int iCount = 0;

	int a, b, temp, k; // temp

	int iNumAres = (iNumCoord) * (iNumCoord - 1)/2;
	while(iCount < iNumCoord - 1)
	{
		a = (Grafo + i)->i; b = (Grafo + i)->j;
		if (Node_check[a] != Node_check[b])
		{
			// printf("%d %d %f\n", a, b, (Grafo + i)->dist);
			if (Node_check[a] <= Node_check[b])
				temp = Node_check[a];
			else
				temp = Node_check[b];
			a = Node_check[a];
			b = Node_check[b];

			for (k = 0; k < iNumCoord; ++k)
			{
				if (Node_check[k] == a || Node_check[k] == b)
				{
					Node_check[k] = temp;
				}
				// printf("%d ", Node_check[k]);
			}
			// printf("\n");

			iTotal += (Grafo + i)->dist;
			iCount++;
		}

		i++;
	}

	printf("%.2f\n", iTotal/100);
}

int main(int argc, char const *argv[])
{
	// struct timeval inicio, final;
 //    int tmili;
	// gettimeofday(&inicio, NULL);
	// int inicio, final, tmili; 
 	// inicio = GetTickCount();

	int iN; // Número de casos
	scanf("%d", &iN);

	int 	iCountTest = 0,
			iCountCoord;
	int iNumCoord; // n <= 500

	int iIndex;

	Person *pCoord;
	pCoord = (Person*) malloc(500 * sizeof(Person));
	int *Node_check;
	Node_check = (int*) malloc(500 * sizeof(int));

	Aresta *Grafo;
	Grafo = (Aresta*) malloc(124750 * sizeof(Aresta)); // Criação da matriz de grafos;

	int i, j;

	while(iCountTest < iN)
	{
		scanf("%d", &iNumCoord); // Número de persoas para passar as coordenadas

		for (iCountCoord = 0; iCountCoord < iNumCoord; ++iCountCoord)
		{
			// 0 <= x, y, <= 10^4
			scanf("%d %d", &pCoord[iCountCoord].x, &pCoord[iCountCoord].y);
		}
		
		// Calculando distancias pra criar a matriz
		iIndex = 0;
		for (i = 0; i < iNumCoord; ++i)
		{
			for (j = i + 1; j < iNumCoord; ++j)
			{
				(Grafo + iIndex)->dist = CalcDist(pCoord[i].x, pCoord[i].y, pCoord[j].x, pCoord[j].y);
				(Grafo + iIndex)->i = i;
				(Grafo + iIndex)->j = j;
				iIndex++;
			}
		}
		quickSort(Grafo, 0, iIndex - 1);
		// PrintGrafo(Grafo, iIndex);
		// printf("Escolhendo as arestas:\n");
		DistMin(Grafo, iNumCoord, Node_check);

		iCountTest++;
	}

	free(pCoord);
	free(Grafo);
	free(Node_check);

	// gettimeofday(&final, NULL);
 //    tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
	// final = GetTickCount();
 	// tmili = final - inicio;
    //printf("tempo decorrido: %d\n", tmili);
	return 0;
}