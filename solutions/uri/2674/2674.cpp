/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/en/problems/view/2674
 * 2674 - Super Primes: Engage!
*/

// Super
// Nada
// Primo

#include <iostream>
#include <vector>

#define MAXNUM 100000

class Crive
{
private:
	std::vector<bool> table;
	unsigned long long maxNum;

public:
	Crive(unsigned long long);
	~Crive();
	void verifyPrimes();
};

Crive::Crive(unsigned long long maxNumTable)
{
	this->maxNum = maxNumTable;
	this->table.resize(maxNumTable + 1, true);
	this->table[0] = false;
	this->table[1] = false;
}

Crive::~Crive()
{
}

void Crive::verifyPrimes()
{
	// first make odd
	// even
	// mark in table false if not prime

	for (unsigned long long i = 2; i * i < this->maxNum; i++)
	{
		for (unsigned long long j = i; j < this->maxNum; j +=)
		{
		}
	}
}

bool isSuper(std::string)
{
}

int main()
{
	const std::vector<bool> digits = {false, false, true, true, false, true, false, true, false, true};
	unsigned long long n;

	Crive crive(MAXNUM);

	while (std::cin >> n)
	{
		std::cout << n << '\n';
	}
	return 0;
}
