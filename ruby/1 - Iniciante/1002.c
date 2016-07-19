#include <stdio.h>

int main(int argc, char const *argv[])
{
	double raio;
	scanf("%lf",&raio);

	raio = raio * raio;

	printf("A=%.4lf\n", 3.14159 * raio);
	return 0;
}