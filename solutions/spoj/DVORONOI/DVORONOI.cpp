/*
 * Yuri Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/DVORONOI/
 * DVORONOI
*/

#include <iostream>
#include <iomanip> // std::setprecision

class Point {
public:
	int x, y, z;

	Point () {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	};
	virtual ~Point () {};

	// add vectors
	void add (Point a) {
		this->x += a.x;
		this->y += a.y;
		this->z += a.z;
	}

	// subtract vectors
	void sub (Point a) {
		this->x -= a.x;
		this->y -= a.y;
		this->z -= a.z;
	}

	// DET with this, q, r vectors
	double det (Point q, Point r) {
		int det = this->x * (q.y*r.z - q.z*r.y) - this->y * (q.x*r.z - q.z*r.x) + this->z * (q.x*r.y - q.y*r.x);
		if (det < 0) det *= -1;
		return (double) det;
	}
};

int main(int argc, char const *argv[]) {
	int t;

	// input points
	Point a, b, c, d;

	// number of tests
	std::cin >> t;

	while (t--) {
		// vectors
		Point p, q, r;

		std::cin >> a.x >> a.y >> a.z;
		std::cin >> b.x >> b.y >> b.z;
		std::cin >> c.x >> c.y >> c.z;
		std::cin >> d.x >> d.y >> d.z;
		p.add(a); p.sub(d); // P = A - D
		q.add(b); q.sub(d); // Q = B - D
		r.add(c); r.sub(d); // R = C - D

		// Calc volume with det
		std::cout << std::setprecision(6) << std::fixed << (p.det(q, r)/6) << '\n';
	}
	return 0;
}
