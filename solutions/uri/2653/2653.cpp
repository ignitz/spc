/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/en/problems/view/2653
 * 2653 - Dijkstra
*/

#include <iostream>
#include <set>

int main()
{
	std::string line;
	std::set<std::string> joias;

	while (std::getline(std::cin, line))
	{
		joias.insert(line);
	}
	std::cout << joias.size() << '\n';

	return 0;
}
