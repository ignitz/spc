/*
 * Yuri Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/ENCOTEL/
 * ENCOTEL
 */

#include <iostream>

inline char get_char_in_hash(char c) {
	switch (c) {
		case 'A':
		case 'B':
		case 'C':
			return '2';
		case 'D':
		case 'E':
		case 'F':
			return '3';
		case 'G':
		case 'H':
		case 'I':
			return '4';
		case 'J':
		case 'K':
		case 'L':
			return '5';
		case 'M':
		case 'N':
		case 'O':
			return '6';
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
			return '7';
		case 'T':
		case 'U':
		case 'V':
			return '8';
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			return '9';
		default:
			return c;
	}
}

int main(){
	std::string tel_num;
	while (std::cin >> tel_num) {
		std::string response;
		for (int i = 0; i < tel_num.size(); i++) {
			response += get_char_in_hash(tel_num[i]);
		}
		std::cout << response << '\n';
	};
	return 0;
}
