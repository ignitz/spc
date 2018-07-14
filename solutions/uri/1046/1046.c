#include <stdio.h>
#include <string.h>

// https://www.urionlinejudge.com.br/judge/pt/problems/view/1046

int main()
{
    int start_hour, end_hour, total;
    scanf("%d %d", &start_hour, &end_hour);

    if (start_hour < end_hour)
    {
        total = end_hour - start_hour;
    }
    else if (start_hour == end_hour)
    {
        total = 24;
    }
    else
    {
        total = end_hour + 24 - start_hour;
    }

    printf("O JOGO DUROU %d HORA(S)\n", total);

    return 0;
}
