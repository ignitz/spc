/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=&problem=949&mosmsg=Submission%20received%20with%20ID%2013698361
 * UVa10008
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Dic {
public:
	char ch;
	int number;

	Dic (char c, int init) {
		this->ch = c;
		this->number = init;
	}
	virtual ~Dic () {}

	bool operator< (const Dic &other) const { // For Sort
		if (number != other.number)
			return number > other.number;
		return ch < other.ch;
  }
};

int main(){
	int n;
	std::string in_word, entire_word;
	std::vector<Dic> map_char; // 'A' = 65 to 'Z' = 90

	for (int i = 0; i < 26; i++)
		map_char.push_back(Dic(char(65 + i), 0));

	std::cin >> n;

	std::getline (std::cin, in_word); // to get '\n' after read n
	for (int i = 0; i < n; i++) {
		std::getline (std::cin, in_word);
		entire_word += in_word;
	}
	std::transform(entire_word.begin(), entire_word.end(), entire_word.begin(), ::toupper); // to UPPERCASE

	for (int i = 0; i < entire_word.size(); i++) {
		if (entire_word[i] >= 'A' && entire_word[i] <= 'Z') {
			map_char[int(entire_word[i]) - int('A')].number++;
		}
	}
	std::sort(map_char.begin(), map_char.end());
	for (int i = 0; i < 26; i++) {
		if (map_char[i].number) {
			std::cout << map_char[i].ch << ' ' << map_char[i].number << '\n';
		}
	}

	return 0;
}
