/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/en/problems/view/1904
 * 1904 - Odds and Evens 2.0
*/

#include <iostream>
#include <vector>
#include <cmath>

// Peguei o algoritmo do crivo de erastótoles neste link
// https://codereview.stackexchange.com/questions/153447/segmented-sieve-of-eratosthenes

#define MAX 10000000

typedef std::vector<bool> VB;
typedef std::vector<int> VI;

VI primes;

static int findPrimes(int n)
{
	int i;
	int sqrtn = sqrt(n);
	VB is_prime(n + 1, true);

	for (i = 3; i <= sqrtn; i += 2)
	{
		if (is_prime[i])
		{
			int increment = i + i;
			primes.push_back(i);
			for (int j = i * i; j <= n; j += increment)
			{
				is_prime[j] = false;
			}
		}
	}
	for (; i <= n; i += 2)
	{
		if (is_prime[i])
			primes.push_back(i);
	}
}

int segmented_sieve(int m, int n)
{
	int count = 0;
	int range = n - m;
	VB is_prime(range + 1, true);

	for (int prime : primes)
	{
		int increment = prime + prime;
		// Start should be the first multiple of prime >= m, or prime^2,
		// whichever is larger.  Also make sure start is odd.
		int start = std::max(((m + prime - 1) / prime) * prime, prime * prime);
		if ((start & 1) == 0)
			start += prime;
		// Adjust to range so we don't have to subtract m in the loop.
		start -= m;
		for (int i = start; i <= range; i += increment)
		{
			is_prime[i] = false;
		}
	}

	if (m <= 2 && n >= 2)
	{
		count++;
	}
	for (int k = (m & 1) ? 0 : 1; k <= range; k += 2)
		if (is_prime[k])
			count++;

	return count;
}

void swapValues(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a, b;
	bool flag;

	std::cin >> a >> b;
	if (a == b)
	{
		std::cout << "?\n";
		return 0;
	}
	if (a > b)
		swapValues(&a, &b);

	int dist = std::abs(a - b);

	int numPrimes = 0;

	if (a == 2 && b == 3)
	{
		std::cout << "Bob\n";
		return 0;
	}

	findPrimes(sqrt(MAX));
	numPrimes = segmented_sieve(a, b);

	if (a == 0 || a == 1)
		numPrimes--;
	// numPrimes = countPrimesInRange(a, b);

	// Usei este teorema pra se na comparação bit a bit
	// estiver incluso no número maior pode dizer a paridade
	// de C(n,k) sem precisar calcular.
	// https://pt.wikipedia.org/wiki/Teorema_de_Lucas
	int bitloko = (dist + numPrimes - 1) & dist;

	if (bitloko == dist)
		std::cout << "Alice\n";
	else
		std::cout << "Bob\n";

	return 0;
}
