/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2500
 * 11505 - Logo
*/

#include <iostream>
#include <cmath>
#include <string>

class Turtle {
private:
	double x, y;
	int angle;
	double pi;

public:
	Turtle () {
		x = y = 0.0;
		angle = 0;
		pi = std::acos(-1);
	}
	virtual ~Turtle () {}

	void go_turtle(std::string command, int number) {
		if (command.compare("fd") == 0) {
			x += ((double)(number)*std::cos(((double) angle)*pi/180));
			y += ((double)(number)*std::sin(((double) angle)*pi/180));
		}
		else if (command.compare("bk") == 0) {
			x += -((double)(number)*std::cos(((double) angle)*pi/180));
			y += -((double)(number)*std::sin(((double) angle)*pi/180));
		}
		else if (command.compare("lt") == 0) {
			angle += number;
			angle %= 360;
		}
		else if (command.compare("rt") == 0) {
			angle -= number;
			angle %= 360;
		}
	}

	int dist() {
		return (int)(std::round(std::sqrt(x*x + y*y)));
	}
};

int main(int argc, char const *argv[]) {
	int num_tests;
	int num_commands;

	std::string command;
	int number;

	std::cin >> num_tests;
	while (num_tests--) {
		Turtle turtle;

		std::cin >> num_commands;
		while (num_commands--) {
			std::cin >> command >> number;
			turtle.go_turtle(command, number);
		}

		std::cout << turtle.dist() << '\n';
	}
	return 0;
}
