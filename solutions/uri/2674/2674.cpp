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
#include <string>
#include <algorithm>

#define MAXNUM 100000

class Sieve
{
  private:
	std::vector<bool> table;
	unsigned long long maxNum;

  public:
	Sieve(unsigned long long);
	~Sieve();
	void verifyPrimes();
	void printAllPrimes();
	bool isPrime(unsigned long long n);
};

Sieve::Sieve(unsigned long long maxNumTable)
{
	this->maxNum = maxNumTable;
	this->table.resize(maxNumTable + 1, true);
	this->table[0] = false;
	this->table[1] = false;
}

Sieve::~Sieve()
{
}

void Sieve::verifyPrimes()
{
	// first make odd
	// even
	// mark in table false if not prime

	for (unsigned long long i = 2; i * i <= this->maxNum; i++)
	{
		if (this->table[i] == true)
		{
			for (unsigned long long j = i * i; j <= this->maxNum; j += i)
			{
				this->table[j] = false;
			}
		}
	}
}

void Sieve::printAllPrimes()
{
	for (unsigned long long p = 2; p <= this->maxNum; p++)
	{
		if (table[p])
			std::cout << p << '\n';
	}
}

bool Sieve::isPrime(unsigned long long n)
{
	return table[n];
}

const std::vector<bool> digits = {false, false, true, true, false, true, false, true, false, false};

bool isSuper(unsigned long long number)
{
	std::string str = std::to_string(number);
	for (char &c : str)
	{
		int digit = c - '0';
		if (digits[digit] == false)
			return false;
	}
	return true;
}

int main()
{
	unsigned long long n;
	std::vector<unsigned long long> ns;

	while (std::cin >> n)
	{
		ns.push_back(n);
	}

	unsigned long long nMax = *std::max_element(ns.begin(), ns.end());
	Sieve sieve(nMax);
	sieve.verifyPrimes();
	for (auto &num : ns)
	{
		if (sieve.isPrime(num))
		{
			if (isSuper(num))
				std::cout << "Super\n";
			else
				std::cout << "Primo\n";
		}
		else
		{
			std::cout << "Nada\n"; // Like is my life
		}
	}

	return 0;
}
