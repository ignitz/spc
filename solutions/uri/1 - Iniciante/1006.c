#include <stdio.h>

int main(int argc, char const *argv[])
{
	double A, B, C;
	scanf("%lf", &A);
	scanf("%lf", &B);
	scanf("%lf", &C);

	A = A * 2.0;
	B = B * 3.0;
	C = C * 5.0;

	printf("MEDIA = %.1lf\n", (A + B + C)/10.0);
	return 0;
}