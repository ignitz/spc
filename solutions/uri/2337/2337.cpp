/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/en/problems/view/2337
 * 2337 - Pro Ability
*/

#include <iostream>
#include <algorithm>

// The probability of two tails one after another is
// http://mathworld.wolfram.com/CoinTossing.html
// F_{n+2} / 2^n

// Below are the fibbonaci implementation that i see
// in this link:
// https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

// Create an array for memoization
#define MAX 50 // O que na real é 40 + 2 mas dei uma folga
unsigned long long f[MAX] = {0};

// Returns n'th fibonacci number using table f[]
unsigned long long fib(unsigned long long n)
{
	// Base cases
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return (f[n] = 1);

	// If fib(n) is already computed
	if (f[n])
		return f[n];

	unsigned long long k = (n & 1) ? (n + 1) / 2 : n / 2;

	// Applyting above formula [Note value n&1 is 1
	// if n is odd, else 0.
	f[n] = (n & 1) ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1))
				   : (2 * fib(k - 1) + fib(k)) * fib(k);

	return f[n];
}

std::pair<unsigned long long, unsigned long long> calcProb(unsigned long long n)
{
	unsigned long long first = fib(n + 2);

	unsigned long long second = 1;
	for (unsigned long long i = 0; i < n; i++)
		second *= 2;
	unsigned long long gcd = std::__gcd(first, second);
	while (gcd != 1)
	{
		first /= gcd;
		second /= gcd;
		gcd = std::__gcd(first, second);
	}
	return std::make_pair(first, second);
}

int main()
{
	int n;

	while (std::cin >> n)
	{
		auto pair = calcProb(n);
		std::cout << pair.first << '/' << pair.second << '\n';
	}

	return 0;
}
