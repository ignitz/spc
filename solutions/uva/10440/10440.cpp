/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1381
 * 10440 - Ferry Loading II
*/

// Algoritmo guloso

#include <iostream>
#include <vector>

int main()
{
	int c, n, t, m;
	int aux;
	int idaEVolta;
	int temp, totalTime;
	int numberOfTrips;
	int indexBalsa;

	std::cin >> c;
	while (c--)
	{
		// Each test case begins with n, t, m. m lines
		// follow, each giving the arrival time for a car
		// (in minutes since the beginning of the day).
		// The operator can run the ferry whenever he
		// or she wishes, but can take only the cars
		// that have arrived up to that time.
		std::cin >> n >> t >> m;

		// There is a ferry across the river that can take n
		// cars across the river in t minutes and return in t minutes.
		idaEVolta = t + t;

		std::vector<int> arrivalTime;
		for (int i = 0; i < m; i++)
		{
			std::cin >> aux;
			arrivalTime.push_back(aux);
		}

		indexBalsa = (m + n - 1) % n;

		totalTime = 0;

		while (indexBalsa < m)
		{
			if (totalTime > arrivalTime[indexBalsa])
			{
				temp = totalTime;
			}
			else
			{
				temp = arrivalTime[indexBalsa];
			}
			totalTime = temp + idaEVolta;

			indexBalsa += n;
		}

		numberOfTrips = (m + n - 1) / n;

		std::cout << (totalTime - t) << ' ' << numberOfTrips << '\n';

		arrivalTime.clear();
	}
	return 0;
}
