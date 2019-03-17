/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=87
 * 151 - Power Crisis
*/

#include <iostream>
#include <vector>

#define DESIRED_POSITION 13

int g(int n, int k)
{
	if (n == 0)
		return 0;
	else
	{
		return (g(n - 1, k) + k) % n;
	}
}

// int main(int argc, char const *argv[])
// {
// 	int n;
// 	while (true)
// 	{
// 		std::cin >> n;
// 		std::vector<int> posicoes(0, n);
// 		if (n == 0)
// 			break;
// 		for (int k = 2; k < n; k++)
// 		{
// 			auto res = g(n, k);
// 			if (res == DESIRED_POSITION)
// 			{
// 				std::cout << k - 1 << '\n';
// 				break;
// 			}
// 		}
// 	}

// 	return 0;
// }

int main()
{
	// for (int i = 1; i < 32; i++)
	// {
	// 	std::cout << "i = " << i << ' ' << "\tg(n,k) = " << g(i, 6) + 1 << '\n';
	// }
	std::cout << "i = " << 50 << ' ' << "\tg(n,k) = " << g(50, 10) + 1 << '\n';
	return 0;
}
