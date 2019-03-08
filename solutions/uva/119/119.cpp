/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=55
 * 119 - Greedy Gift Givers
*/

#include <iostream>
#include <map>
#include <iterator>
#include <vector>

int maratona()
{
	int n;
	int count = 0;
	// 	The input is a sequence of gift-giving groups. A group consists of several lines:
	// the number of people in the group,
	while (std::cin >> n)
	{
		if (count > 0)
			std::cout << '\n';

		std::map<std::string, int> bolso;
		std::vector<std::string> names;
		// a list of the names of each person in the group,
		for (size_t i = 0; i < n; i++)
		{
			std::string input;
			std::cin >> input;
			bolso.insert(std::pair<std::string, int>(input, 0));
			names.push_back(input);
		}

		int amountMoney;
		int numberOfPeople;

		for (int i = 0; i < n; i++)
		{
			std::string name;
			// a line for each person in the group
			// consisting of the name of the person,
			// the amount of money spent on gifts
			std::cin >> name >> amountMoney >> numberOfPeople;
			bolso[name] += numberOfPeople > 0 ? -amountMoney + (amountMoney % numberOfPeople) : 0;
			for (int j = 0; j < numberOfPeople; j++)
			{
				std::cin >> name;
				bolso[name] += amountMoney / numberOfPeople;
			}

			//  the number of people to whom gifts are given, and the names of those to whom
			// gifts are given.
			// All names are lower-case letters, there are no more than 10 people in a group, and no name is more
			// than 12 characters in length. Money is a non-negative integer less than 2000.
			// The input consists of one or more groups and is terminated by end-of-file.
		}

		for (auto &name : names)
		{
			std::cout << name << ' ' << bolso[name] << '\n';
		}
		count++;
	}
	return 0;
}

int main()
{
	maratona();
	return 0;
}
