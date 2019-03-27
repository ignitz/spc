/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=578
 * 637 - Booklet Printing
*/

#include <iostream>

void printSheets(int n)
{
	if (n == 1)
	{
		std::cout << "Sheet 1, front: Blank, 1" << '\n';
		return;
	}
	int rest = n % 4;
	int i = 1;
	int back;
	do
	{
		std::cout << "Sheet " << i << ", front: ";
		switch (rest)
		{
		case 0:
			std::cout << n - 2 * (i - 1) << ", " << (2 * i - 1) << '\n';
			break;
		case 1:
			back = n - 2 * (i - 1) + 3;
			if (back > n)
				std::cout << "Blank";
			else
				std::cout << back;
			std::cout << ", " << (2 * i - 1) << '\n';
			break;
		case 2:
			back = n - 2 * (i - 1) + 2;
			if (back > n)
				std::cout << "Blank";
			else
				std::cout << back;
			std::cout << ", " << (2 * i - 1) << '\n';
			break;
		case 3:
			back = n - 2 * (i - 1) + 1;
			if (back > n)
				std::cout << "Blank";
			else
				std::cout << back;
			std::cout << ", " << (2 * i - 1) << '\n';
			break;
		}
		std::cout << "Sheet " << i << ", back : ";
		switch (rest)
		{
		case 0:
			std::cout << 2 * i << ", " << n - 2 * (i - 1) - 1 << '\n';
			break;
		case 1:
			std::cout << 2 * i << ", ";
			back = n - 2 * (i - 1) + 2;
			if (back > n)
				std::cout << "Blank\n";
			else
				std::cout << back << '\n';
			break;
		case 2:
			std::cout << 2 * i << ", ";
			back = n - 2 * (i - 1) + 1;
			if (back > n)
				std::cout << "Blank\n";
			else
				std::cout << back << '\n';
			break;
		case 3:
			std::cout << 2 * i << ", ";
			back = n - 2 * (i - 1);
			if (back > n)
				std::cout << "Blank\n";
			else
				std::cout << back << '\n';
			break;
		}
		i++;
	} while (i < (n + 7) / 4);
	return;
}

void printPages(int n)
{
	std::cout << "Printing order for " << n << " pages:\n";
	printSheets(n);
}

int main()
{
	int n;
	while (std::cin >> n)
	{
		if (n == 0)
			break;
		printPages(n);
	}

	return 0;
}
