#include <stdio.h>

int main(int argc, char const *argv[])
{
	int ID, horas;
	double money;

	scanf("%d", &ID);
	scanf("%d", &horas);
	scanf("%lf", &money);

	printf("NUMBER = %d\nSALARY = U$ %.2lf\n", ID, horas * money);

	return 0;
}