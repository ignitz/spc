/*
 * Yuri Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/PARPROX/
 * PARPROX
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

class Point {
public:
  double x, y;

  Point(double x, double y) {
    this->x = x;
    this->y = y;
  }
  virtual ~Point () {}

  double dist(Point p2) {
    return std::sqrt((this->x - p2.x)*(this->x - p2.x) + (this->y - p2.y)*(this->y - p2.y));
  }
};

int main(int argc, char const *argv[]) {
  int n;
  double x, y;
  std::cin >> n;

  std::vector<Point> points;

  double dist = 4000000.0;

  while (n > 0) {
    std::cin >> x >> y;
    Point p(x, y);
    for (auto const point : points)
      dist = std::min(dist, p.dist(point));
    points.push_back(p);
    n--;
  }

  std::cout << std::fixed << std::setprecision(3);
  std::cout << dist << '\n';
  return 0;
}
