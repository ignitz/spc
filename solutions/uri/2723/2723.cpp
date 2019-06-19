/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/en/problems/view/2723
 * 2723 - Balancing Gifts
*/

#include <iostream>

int main()
{
	int t, n, pi;
	int diff;
	bool natalino;

	std::cin >> t;

	while (t--)
	{
		diff = 0;
		natalino = true;
		std::cin >> n;
		while (n--)
		{
			std::cin >> pi;
			if (diff < 0)
			{
				if (diff + pi <= 5)
				{
					diff += pi;
				}
				else if (diff - pi >= -5)
				{
					diff -= pi;
				}
				else
				{
					natalino = false;
					break;
				}
			}
			else
			{
				if (diff - pi >= -5)
				{
					diff -= pi;
				}
				else if (diff + pi <= 5)
				{
					diff += pi;
				}
				else
				{
					natalino = false;
					break;
				}
			}
		}
		if (natalino)
			std::cout << "Feliz Natal!" << '\n';
		else
			std::cout << "Ho Ho Ho!" << '\n';
	}

	return 0;
}
