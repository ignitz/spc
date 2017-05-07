#include <stdio.h>
#include <stdlib.h>

void print_gene(int *a, int N)
{
    int iIndex = 0;
    while(iIndex < N)
    {
        printf("%d ", a[iIndex]);
        iIndex++;
    }
    printf("\n");
}

void inversao(int *a, int *b)
{
    int temp;
    while(a < b)
    {
        temp    = *a;
        *a      = *b;
        *b      = temp;
        a++; b--;
    }
    return;
}

int main(int argc, char const *argv[])
{
    int     *gene;  // Genes

    int     N,      // 1 ≤ N ≤ 50000 numero de genes
            R,      // 0 ≤ R ≤ 1000 numero de inversoes
            Q;      // 0 ≤ Q ≤ 100 n de consultas de genes
    
    int     i, j,   // Índices 1 ≤ i ≤ j ≤ N
            iIndice[1000], jIndice[1000];
    int count,          // contador pra loops
        case_cnt = 1;   // contador de casos

    while(scanf("%d", &N) == 1 && N > 0)
    {
        gene = (int*) malloc(sizeof(int)*N);
        for (count = 1; count <= N; count++)
            gene[count-1] = count;

        scanf("%d", &R);

        for (count = 0; count < R; count++)
            scanf("%d %d", &iIndice[count], &jIndice[count]);

        for (count = R - 1; count >= 0; count--)
        {
            inversao(gene + iIndice[count] - 1, gene + jIndice[count] - 1);

            // printf("****************\nEstado do gene:\n");
            // print_gene(gene,N);
            // printf("****************\n\n");

        }

        scanf("%d", &Q);
        
        printf("Genome %d\n", case_cnt);
        
        for (count = 0; count < Q; count++)
        {
            scanf("%d", &i);
            printf("%d\n", gene[i - 1]);
        }

        // Aqui coloco a função que irá imprimir as Q + 1 linhas
        free(gene);
        case_cnt++;
    }

    return 0;
}