/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1524
 * 10583 - Ubiquitous Religions
*/

// Se resolve com união de conjuntos
// Já resolvi no URI 1082, vou copiar o código e adaptar

#include <iostream>
#include <set>
#include <cmath>

//finding root of an element.
int root(int Arr[], int i)
{
	while (Arr[i] != i) //chase parent of current element until it reaches root.
	{
		i = Arr[i];
	}
	return i;
}

/*modified union function where we connect the elements by changing the root of one of the element */

std::pair<int, int> unionTwoSets(int Arr[], int A, int B)
{
	int resA = root(Arr, A);
	int resB = root(Arr, B);
	int root_A = std::min(resA, resB);
	int root_B = std::max(resA, resB);
	Arr[root_B] = root_A; //setting parent of root(A) as root(B).
	return std::make_pair(root_A, root_B);
}

bool find(int Arr[], int A, int B)
{
	if (root(Arr, A) == root(Arr, B)) //if A and B have same root,means they are connected.
		return true;
	else
		return false;
}

int main()
{
	int n, m;
	int i, j;
	std::set<int> myset;

	int countCase = 1;
	while (std::cin >> n >> m)
	{
		if (!n && !m)
			break;
		int Arr[n + 1];
		while (n--)
			Arr[n + 1] = n + 1;
		Arr[0] = 0;

		while (m--)
		{
			std::cin >> i >> j;
			auto res = unionTwoSets(Arr, i, j);
		}

		for (auto &element : Arr)
		{
			if (element > 0)
				myset.insert(root(Arr, element));
		}

		std::cout << "Case " << countCase++ << ": " << myset.size() << '\n';
		myset.clear();
	}

	// code
	return 0;
}
