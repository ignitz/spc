/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=386
 * 445 - Marvelous Mazes
*/

#include <iostream>

// read numbers
// read letter
// read !
// let's go

std::string drawMaze(std::string line)
{
	char toAdd;
	std::string response;
	int manyCharTimes = 0;

	for (auto &c : line)
	{
		if (c == '!')
		{
			response += '\n';
			continue;
		}
		if (isdigit(c))
		{
			manyCharTimes += (int)(c - '0');
			continue;
		}
		else
		{
			toAdd = (c == 'b') ? ' ' : c;
			for (int i = 0; i < manyCharTimes; i++)
			{
				response += toAdd;
			}
			manyCharTimes = 0;
			continue;
		}
	}

	return response;
}

int main()
{
	std::string line, output;

	while (std::getline(std::cin, line))
	{
		output = drawMaze(line);
		std::cout << output << '\n';
	}
	// code
	return 0;
}
