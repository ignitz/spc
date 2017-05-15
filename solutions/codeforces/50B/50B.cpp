/*
 * Yuri Niitsuma
 * 2011039023
 * http://codeforces.com/problemset/problem/50/B
 * 50B
 */

#include <iostream>
#include <string.h>

int main(){
	std::string in_word;
	std::cin >> in_word;
	int size = in_word.size();
	long long map_char[256];
	// std::fill(map_char, map_char + 256, 0);
	memset(map_char, 0, 256*sizeof(long long));

	long long count = 0;

	for (int i = 0; i < size; ++i)
		map_char[int(in_word[i])]++;
	count = 0;
	for (int i = 0; i < 256; ++i)
		count += map_char[i]*map_char[i];
	std::cout << count << std::endl;
	return 0;
}
