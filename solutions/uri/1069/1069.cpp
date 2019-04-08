/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/en/problems/view/1069
 * 1069 - Diamonds and Sand
*/

#include <iostream>

// class Stack
// {
// private:
// public:
// 	Stack(/* args */);
// 	~Stack();
// };

// Stack::Stack(/* args */)
// {
// }

// Stack::~Stack()
// {
// }

int main()
{
	std::string line;

	int n;
	int count;
	int numDiamonds;

	std::getline(std::cin, line);
	n = std::stoi(line);

	while (n--)
	{
		std::getline(std::cin, line);
		count = 0;
		numDiamonds = 0;
		for (char &c : line)
		{
			if (c == '<')
				count++;
			else if (count > 0 && c == '>')
			{
				count--;
				numDiamonds++;
			}
		}
		std::cout << numDiamonds << '\n';
	}
	return 0;
}
