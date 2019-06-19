/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/en/problems/view/1602
 * 1602 - Hyperprimes
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Sieve
{
private:
	std::vector<bool> table;
	int maxNum;
	std::vector<int> numDiv;

public:
	Sieve(int);
	~Sieve();
	void verifyPrimes();
	void printAllPrimes();
	bool isPrime(int);
	int primeFactors(int);
	bool isHyperPrime(int);
};

Sieve::Sieve(int maxNumTable)
{
	this->maxNum = maxNumTable;
	this->table.resize(maxNumTable + 1, true);
	this->numDiv.resize(maxNumTable + 1, 0);
	this->numDiv[0] = 0;
	this->numDiv[1] = 1;

	this->table[0] = false;
	this->table[1] = false;

	verifyPrimes();
}

Sieve::~Sieve()
{
}

void Sieve::verifyPrimes()
{
	// first make odd
	// even
	// mark in table false if not prime

	for (int i = 2; i * i <= this->maxNum; i++)
	{
		if (this->table[i] == true)
		{
			for (int j = i * i; j <= this->maxNum; j += i)
			{
				this->table[j] = false;
			}
		}
	}
}

void Sieve::printAllPrimes()
{
	for (int p = 2; p <= this->maxNum; p++)
	{
		if (table[p])
			std::cout << p << '\n';
	}
}

bool Sieve::isPrime(int n)
{
	return table[n];
}

int Sieve::primeFactors(int n)
{
	if (n == 1)
		return 1;
	if (numDiv[n] > 0)
		return numDiv[n];

	if (table[n])
	{
		numDiv[n] = 2;
		return 2;
	}

	int response = 0, aux = 0, originalN = n;
	while (n % 2 == 0)
	{
		n = n / 2;
		// n >>= 1;
		aux++;
	}

	response = aux + 1;
	aux = 0;

	// n must be odd at this point.  So we can skip
	// one element (Note i = i +2)
	for (int i = 3; i * i <= n; i = i + 2)
	{
		while (n % i == 0)
		{
			n = n / i;
			aux++;
		}
		response *= aux + 1;
		aux = 0;
	}

	if (n > 2)
		response *= 2;

	numDiv[originalN] = response;
	return response;
}

bool Sieve::isHyperPrime(int n)
{
	return table[primeFactors(n)];
}

int main()
{
	std::vector<int> ns;
	int n;

	while (std::cin >> n)
		ns.push_back(n);

	// Do the work
	int nMax = *std::max_element(ns.begin(), ns.end());
	Sieve sieve(nMax);
	int aux = 0;
	std::vector<int> answers;
	answers.push_back(0);
	answers.push_back(0);
	for (int i = 2; i <= nMax; i++)
	{
		if (sieve.isHyperPrime(i))
			aux++;
		answers.push_back(aux);
	}

	for (auto num : ns)
	{
		std::cout << answers[num] << '\n';
	}
}
