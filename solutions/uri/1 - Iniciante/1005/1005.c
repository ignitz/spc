#include <stdio.h>

int main(int argc, char const *argv[])
{
	double A, B;
	scanf("%lf", &A);
	scanf("%lf", &B);

	A = A * 3.5;
	B = B * 7.5;

	printf("MEDIA = %.5lf\n", (A + B)/11.0);
	return 0;
}