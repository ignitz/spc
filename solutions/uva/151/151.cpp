/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=87
 * 151 - Power Crisis
*/

// Similiar to Josephus problem but generalized
// To understand more watch this Numberphile video
// https://www.youtube.com/watch?v=uCsD3ZGzMgE

#include <iostream>
#include <vector>

#define DESIRED_POSITION 13

std::vector<int> genJosephusMaroto(int maxQuery)
{
	std::vector<int> results;

	int m; // jumper
	int position, count;

	for (int k = DESIRED_POSITION; k <= maxQuery; k++)
	{
		m = 1;
		while (true)
		{
			position = 0;
			std::vector<bool> lightOn(maxQuery, true);
			for (int i = 0, count = m; i < k - 1; i++, count = m)
			{
				lightOn[position] = false;
				while (true)
				{
					position = (position + 1) % k;
					count += lightOn[position] ? -1 : 0;
					if (!count)
						break;
				}
			}
			// found
			if (lightOn[DESIRED_POSITION - 1])
				break;
			m++;
		}
		// store results
		results.push_back(m);
	}
	return results;
}

int main(int argc, char const *argv[])
{
	int n, maxValue = 0;

	std::vector<int> inputValues;

	while (true)
	{
		std::cin >> n;
		if (n == 0)
			break;
		inputValues.push_back(n - DESIRED_POSITION);
		maxValue = n > maxValue ? n : maxValue;
	}

	auto josephusValues = genJosephusMaroto(maxValue);
	for (int &value : inputValues)
		std::cout << josephusValues[value] << '\n';

	return 0;
}