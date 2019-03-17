/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=208
 * 272 - TEX Quotes
*/

#include <iostream>

int main()
{
	bool check = true;
	std::string input;
	while (std::getline(std::cin, input))
	{
		for (auto &c : input)
		{
			if (c == '"')
			{
				if (check)
					std::cout << "``";
				else
					std::cout << "''";
				check = !check;
			}
			else
			{
				std::cout << c;
			}
		}
		std::cout << '\n';
	}

	return 0;
}
