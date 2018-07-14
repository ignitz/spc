#include <stdio.h>
#include <stdlib.h>
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
    int *gene, N, R, Q, i, j, iIndice[1000], jIndice[1000], count, case_cnt = 1;
    while(scanf("%d", &N) == 1 && N > 0)
    {
        gene = (int*) malloc(sizeof(int)*N);
        for (count = 1; count <= N; count++)
            gene[count-1] = count;
        scanf("%d", &R);
        for (count = 0; count < R; count++)
            scanf("%d %d", &iIndice[count], &jIndice[count]);
        for (count = R - 1; count >= 0; count--)
            inversao(gene + iIndice[count] - 1, gene + jIndice[count] - 1);
        scanf("%d", &Q);
        printf("Genome %d\n", case_cnt);
        for (count = 0; count < Q; count++)
        {
            scanf("%d", &i);
            printf("%d\n", gene[i - 1]);
        }
        free(gene);
        case_cnt++;
    }
    return 0;
}