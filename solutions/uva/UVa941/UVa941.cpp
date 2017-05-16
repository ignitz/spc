/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=882
 * UVa941 - Permutations
 */

#include <iostream>
#include <algorithm>

int main() {
	std::string in_word;
	int n;
	long long number;
	long long num_perm;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> in_word;
		std::sort(in_word.begin(), in_word.end());
		std::string response;
		num_perm = 1;
		for (long long j = 2; j <= in_word.size(); j++)
			num_perm *= j;

		std::cin >> number;
		long long aux;
		// number %= num_perm;
		for (int j = in_word.size(); j > 1;  j--) {
			num_perm /= j;
			aux = number / (num_perm) % j;
			response += in_word[aux];
			in_word.erase(aux, 1);
		}
		response += in_word[0];
		std::cout << response << '\n';
	}
	return 0;
}
