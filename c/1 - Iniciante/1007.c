#include <stdio.h>

int main(int argc, char const *argv[])
{
	int A, B, C, D;
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	scanf("%d", &D);

	printf("DIFERENCA = %d\n", (A*B - C*D));
	return 0;
}