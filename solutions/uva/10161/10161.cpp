/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1102
 * 10161 - Ant on a Chessboard
*/

#include <iostream>
#include <cmath>
#include <cassert>

struct Response
{
	bool isSquare;
	int root;
};

Response CalcPerfectSquare(int n)
{
	using namespace std;
	Response res;

	assert(n > 0);
	int root(floor(sqrt(n)));
	res.isSquare = n == root * root;
	res.root = root;
	return res;
}

int main()
{
	int n;
	int x, y;
	int timeLeft;
	Response res;
	// int i = 0;
	// while (i++ < 100)
	while (std::cin >> n)
	{
		if (n == 0)
			break;
		// std::cout << "n = " << n << '\n';

		res = CalcPerfectSquare(n);
		if (res.isSquare)
		{
			if (n % 2 == 0)
			{
				x = res.root;
				y = 1;
			}
			else
			{
				x = 1;
				y = res.root;
			}
		}
		else
		{
			timeLeft = n - res.root * res.root;

			if (res.root % 2 == 0)
			{
				if (timeLeft <= res.root + 1)
				{
					// Up
					x = res.root + 1;
					y = timeLeft;
				}
				else
				{
					// Left
					x = 2 * (res.root + 1) - timeLeft;
					y = res.root + 1;
				}
			}
			else
			{
				if (timeLeft <= res.root + 1)
				{
					// Right
					x = timeLeft;
					y = res.root + 1;
				}
				else
				{
					// Down
					x = res.root + 1;
					y = 2 * (res.root + 1) - timeLeft;
				}
			}
		}

		std::cout << x << ' ' << y << '\n';
	}

	return 0;
}
