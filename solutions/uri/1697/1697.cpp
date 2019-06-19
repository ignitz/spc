/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/en/problems/view/1697
 * 1697 - Jaida and Multiply Game
*/

#include <iostream>
#include <vector>
#include <algorithm> // std::fill

#define aiMAX 10000000

class Sieve
{
private:
	std::vector<bool> table;
	int maxNum;

public:
	Sieve(int);
	~Sieve();
	int markNumbers();
	void markOne(int k);
	void clear();
};

Sieve::Sieve(int maxNumTable)
{
	this->maxNum = maxNumTable;
	this->table.resize(maxNumTable + 1, true);
	this->table[0] = false;
}

Sieve::~Sieve()
{
}

int Sieve::markNumbers()
{
	if (table[1])
		return 0;
	int i = 2;
	while (i < this->maxNum)
	{
		if (this->table[i])
		{
			return i - 1;
		}
		else
		{
			for (int j = i + i; j < this->maxNum; j += i)
			{
				this->table[j] = false;
			}
		}
		i++;
	}
}

void Sieve::clear()
{
	// For not need to alloc more memory
	std::fill(table.begin(), table.end(), true);
}

void Sieve::markOne(int k)
{
	this->table[k] = false;
}

int main()
{
	int t, n, input;
	std::vector<int> ns;
	Sieve sieve(4000000);

	std::cin >> t;
	while (t--)
	{
		std::cin >> n;
		while (n--)
		{
			std::cin >> input;
			ns.push_back(input);
		}
		for (auto &num : ns)
			sieve.markOne(num);
		std::cout << sieve.markNumbers() << '\n';

		ns.clear();
		sieve.clear();
	}

	return 0;
}
