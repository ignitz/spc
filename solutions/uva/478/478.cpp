/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=419
 * 478 - Points in Figures: Rectangles, Circles, Triangles
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

bool double_equals(double a, double b, double epsilon = 0.001) {
  return std::abs(a - b) < epsilon;
}

class Figure {
public:
	int type;
	Figure (){};
	virtual ~Figure (){};
};

class Triangle;
class Circle;
class Rectangle;

class Point {
public:
	double x, y;
	Point ();
	Point (double x, double y);
	virtual ~Point ();
	bool in_figure (Figure* tri);
	bool in_triangle (Triangle* tri);
	bool in_circle (Circle* c);
	bool in_rectangle (Rectangle* r);
};

class Triangle: public Figure {
public:
	Point a, b, c; // Points A, B, C

	Triangle (double x1, double y1, double x2, double y2, double x3, double y3) {
		this->a.x = x1; this->a.y = y1;
		this->b.x = x2; this->b.y = y2;
		this->c.x = x3; this->c.y = y3;
		this->type = 1;
	};
	virtual ~Triangle () {};
};

class Circle: public Figure {
public:
	double x, y; // center
	double R; // radius

	Circle (double x, double y, double R) {
		this->x = x; this->y = y; this->R = R;
		this->type = 2;
	}
	virtual ~Circle (){};
};

class Rectangle: public Figure {
public:
	Point upper_left;
	Point lower_right;

	Rectangle (double x1, double y1, double x2, double y2) {
		this->upper_left.x = x1; this->upper_left.y = y1;
		this->lower_right.x = x2; this->lower_right.y = y2;
		this->type = 3;
	};
	virtual ~Rectangle (){};
};

Point::Point () {};
Point::Point (double x, double y) {
	this->x = x; this->y = y;
};
Point::~Point(){};

bool Point::in_figure (Figure *x) {
	if (x->type == 1)
		return in_triangle((Triangle*) x);
	else if (x->type == 2)
		return in_circle((Circle*) x);
	else if (x->type == 3)
		return in_rectangle((Rectangle*) x);
	std::cerr << "/* error message */" << '\n';
	return false;
}

bool Point::in_triangle (Triangle * tri) {
	double area = 0.0;
	double aux;
	double total_area = 0.0;

	// maybe TODO: check if point is inside of edge of triangle
	// calc by DET
	aux = this->x * (tri->a.y - tri->b.y) - this->y * (tri->a.x - tri->b.x) + 1 * (tri->a.x * tri->b.y - tri->a.y * tri->b.x);
	if (double_equals(aux, 0.0)) return false;
	if (aux < 0.0) aux *= -1;
	area += aux;

	aux = this->x * (tri->a.y - tri->c.y) - this->y * (tri->a.x - tri->c.x) + 1 * (tri->a.x * tri->c.y - tri->a.y * tri->c.x);
	if (double_equals(aux, 0.0)) return false;
	if (aux < 0.0) aux *= -1;
	area += aux;

	aux = this->x * (tri->b.y - tri->c.y) - this->y * (tri->b.x - tri->c.x) + 1 * (tri->b.x * tri->c.y - tri->b.y * tri->c.x);
	if (double_equals(aux, 0.0)) return false;
	if (aux < 0.0) aux *= -1;
	area += aux;

	total_area = (tri->b.x*tri->c.y - tri->c.x*tri->b.y) - (tri->a.x*tri->c.y - tri->c.x*tri->a.y) + (tri->a.x*tri->b.y - tri->b.x*tri->a.y);
	if (total_area < 0.0) total_area *= -1;

	return double_equals(area, total_area) ? true : false;
};

bool Point::in_circle (Circle * c) {
	return (this->x - c->x)*(this->x - c->x) + (this->y - c->y)*(this->y - c->y) < c->R*c->R ? true : false;
};

bool Point::in_rectangle (Rectangle * r) {
	if (
		this->x > r->upper_left.x && this->y < r->upper_left.y &&
		this->x < r->lower_right.x && this->y > r->lower_right.y) {
		return true;
	}
	else {
		return false;
	}
};

int main(int argc, char const *argv[]) {
	std::string input;
	std::vector<Figure*> figures;

	double aux1, aux2, aux3, aux4, aux5, aux6;

	while (true) {
		std::cin >> input;
		if (input[0] == '*') {
			break;
		}
		else if (input[0] == 't') { // triangle
			// read 6 values
			std::cin >> aux1 >> aux2 >> aux3 >> aux4 >> aux5 >> aux6;
			figures.push_back(new Triangle(aux1, aux2, aux3, aux4, aux5, aux6));
		}
		else if (input[0] == 'c') { // Circle
			// read 3 values
			std::cin >> aux1 >> aux2 >> aux3;
			figures.push_back(new Circle(aux1, aux2, aux3));
		}
		else if (input[0] == 'r'){
			// read four values
			std::cin >> aux1 >> aux2 >> aux3 >> aux4;
			figures.push_back(new Rectangle(aux1, aux2, aux3, aux4));
		}
		else {
			std::cerr << "/* error message */" << '\n';
			continue;
		}
	}

	int count_point = 1;
	while (std::cin >> aux1 >> aux2) {
		if (aux1 == 9999.9 && aux2 == 9999.9) break;
		bool check = false;
		Point p(aux1, aux2);
		for (int i = 0; i < figures.size(); i++) {
			if (p.in_figure (figures[i])) {
				check = true;
				std::cout << "Point "<< count_point << " is contained in figure " << (i+1) << '\n';
			}
		}
		if (!check) {
			std::cout << "Point " << count_point << " is not contained in any figure" << '\n';
		}

		count_point++;
	}
	return 0;
}
