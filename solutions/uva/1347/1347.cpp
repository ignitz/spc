/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4093
 * 1347 - Tour
*/

// #include <iostream>
// #include <cstdio>
// #include <iomanip>
// #include <cmath>
// using namespace std;
// const int maxn = 61;
// int n;
// double x[maxn], y[maxn];
// double dist[maxn][maxn], len[maxn][maxn];
// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	//freopen("input.txt" , "r", stdin );
// 	//freopen("output.txt", "w", stdout);
// 	while (cin >> n)
// 	{
// 		for (int i = 0; i < n; ++i)
// 			cin >> x[i] >> y[i];
// 		for (int i = 0; i < n; ++i)
// 			for (int j = 0; j < n; ++j)
// 				dist[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) +
// 								  (y[i] - y[j]) * (y[i] - y[j]));
// 		for (int i = n - 2; i > 0; --i)
// 		{
// 			for (int j = 0; j < i; ++j)
// 			{
// 				if (i == n - 2)
// 					len[i][j] = dist[i][n - 1] + dist[j][n - 1];
// 				else
// 					len[i][j] = min(len[i + 1][j] + dist[i + 1][i],
// 									len[i + 1][i] + dist[i + 1][j]);
// 			}
// 		}
// 		double ans = dist[1][0] + len[1][0];
// 		cout.setf(ios::fixed);
// 		cout << setprecision(2) << ans << '\n';
// 	}
// 	return 0;
// }

#include <bits/stdc++.h>

class Graph
{
private:
	int n;
	std::vector<std::pair<int, int>> cities;

public:
	Graph(int n, std::vector<std::pair<int, int>> inputcities);
	~Graph();

	std::pair<int, int> getCoords(int id);
};

Graph::Graph(int n, std::vector<std::pair<int, int>> inputcities)
{
	this->n = n;
	this->cities = inputcities;
}

Graph::~Graph()
{
	cities.clear();
}

/**
 * 1 <= id <= n;
 */
std::pair<int, int> Graph::getCoords(int id)
{
	if (id < 0 || id >= n)
	{
		std::cerr << "getCoords :: Out of range\n"
				  << "min 0 and max " << n - 1 << '\n'
				  << "Received id: " << id << '\n';
		throw "getCoords :: Out of range";
	}
	return cities[id - 1];
}

int main(int argc, char const *argv[])
{
	int n;
	std::vector<std::pair<int, int>> points;

	int inputA, inputB;

	while (std::cin >> n)
	{
		while (n--)
		{
			std::cin >> inputA >> inputB;

			points.push_back(std::make_pair(inputA, inputB));
		}

		points.clear();
	}

	return 0;
}
