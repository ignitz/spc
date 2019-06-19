/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=749
 * 808 - Bee Breeding
*/

// Uma ideia parecida que tá nesse link
// https://keekerdc.com/2011/03/hexagon-grids-coordinate-systems-and-distance-calculations/
// https://www.redblobgames.com/grids/hexagons/

#include <iostream>
#include <utility>
#include <cmath>

#include <cassert>

class HoneyBeeNest
{
  public:
	HoneyBeeNest(/* args */);
	~HoneyBeeNest();
	int len_shortest_path(int a, int b);
	int x_travel(int a, int b);
	int y_travel(int a, int b);
	int x_and_y_travel(int a, int b);
	std::pair<int, int> get_coords(int cell);
	int ring_number(int cell);
	std::pair<int, int> anchor_coords(int ring);
	int anchor_cell(int ring);
	int get_x(int cell);
	int get_y(int cell);
	void printDistance(int a, int b);
	void printCoord(int cell);
};

HoneyBeeNest::HoneyBeeNest(/* args */)
{
}

HoneyBeeNest::~HoneyBeeNest()
{
}

int HoneyBeeNest::len_shortest_path(int a, int b)
{
	int x = this->x_travel(a, b);
	int y = this->y_travel(a, b);
	return (x + y + this->x_and_y_travel(a, b)) / 2;
}

int HoneyBeeNest::x_travel(int a, int b)
{
	return std::abs(this->get_coords(a).first - this->get_coords(b).first);
}

int HoneyBeeNest::y_travel(int a, int b)
{
	return std::abs(this->get_coords(a).second - this->get_coords(b).second);
}

int HoneyBeeNest::x_and_y_travel(int a, int b)
{
	return std::abs(this->get_coords(a).first - this->get_coords(b).first + this->get_coords(a).second - this->get_coords(b).second);
}

std::pair<int, int> HoneyBeeNest::get_coords(int cell)
{
	return (cell == 1) ? std::make_pair(0, 0) : std::make_pair(this->get_x(cell), this->get_y(cell));
}

int HoneyBeeNest::ring_number(int cell)
{
	if (cell == 1)
		return 0;
	// divide number of hexagons in each ring by six and they increase as triangle numbers
	int root = (cell - 2) / 6;
	return static_cast<int>((std::sqrt(8 * root + 1) - 1.0) / 2.0) + 1;
}

std::pair<int, int> HoneyBeeNest::anchor_coords(int ring)
{
	if (ring == 0)
	{
		return std::make_pair(0, 0);
	}
	else
	{
		double b = -(double)ring / (double)2;
		return std::make_pair(ring - 1, std::floor(b));
	}
}

int HoneyBeeNest::anchor_cell(int ring)
{
	return (ring) * (ring - 1) * 3 + 2;
}

int HoneyBeeNest::get_x(int cell)
{
	int ring = this->ring_number(cell);
	auto p = this->anchor_coords(ring);
	int anchor_x = p.first;
	int anchor = this->anchor_cell(ring);
	int hexagon_side = (cell - anchor) / (ring);
	int hindex = (cell - anchor) % ring;
	switch (hexagon_side)
	{
	case 0:
		return anchor_x - hindex;
	case 1:
		return -hindex - 1;
	case 2:
		return -ring;
	case 3:
		return -ring + hindex + 1;
	case 4:
		return hindex + 1;
	case 5:
		return ring;
	default:
		std::cerr << "Invalid x-axis Hexagon side value " << hexagon_side << '\n';
		break;
	}
}

int HoneyBeeNest::get_y(int cell)
{
	int ring = this->ring_number(cell);
	auto p = this->anchor_coords(ring);
	int anchor_y = p.second;
	int anchor = this->anchor_cell(ring);
	int hexagon_side = (cell - anchor) / ring;
	int hindex = (cell - anchor) % ring;
	switch (hexagon_side)
	{
		// case 0:
		// 	return -(1 + hindex);
		// case 1:
		// 	return -ring;
		// case 2:
		// 	return -ring + hindex + 1;
		// case 3:
		// 	return 1 + hindex;
		// case 4:
		// 	return ring;
		// case 5:
		// 	return ring - hindex - 1;

	// case 0:
	// 	return -(-anchor_y + hindex / 2);
	// case 1:
	// 	return -ring + hindex / 2 + 1;
	// case 2:
	// 	return anchor_y + hindex + 1;
	// case 3:
	// 	return -anchor_y + (hindex + 1) / 2;
	// case 4:
	// 	return -(-ring + (hindex + 1) / 2);
	// case 5:
	// 	return -anchor_y - hindex - 1;
	case 0:
		return (-anchor_y + 2 * hindex);
	case 1:
		return -ring + hindex / 2 + 1;
	case 2:
		return anchor_y + hindex + 1;
	case 3:
		return -anchor_y + (hindex + 1) / 2;
	case 4:
		return -(-ring + (hindex + 1) / 2);
	case 5:
		return -2 * anchor_y - hindex - 1;
	default:
		std::cerr << "Invalid y-axis Hexagon side value " << hexagon_side << '\n';
		break;
	}
}

void HoneyBeeNest::printDistance(int a, int b)
{
	std::cout << "The distance between cells " << a << " and " << b << " is " << this->len_shortest_path(a, b) << ".\n";
}

void HoneyBeeNest::printCoord(int cell)
{
	auto p = this->get_coords(cell);
	std::cout << cell << " : (" << p.first << ", " << p.second << ")\n";
}

void maratona()
{
	int a, b;
	HoneyBeeNest honeynest;

	while (std::cin >> a >> b)
	{
		if (!(a && b))
			break;
		honeynest.printDistance(a, b);
	}
}

int main()
{
	HoneyBeeNest honeynest;
	// maratona();
	// for (int i = 1; i < 3000; i++)
	// {
	// auto p = honeynest.get_coords(i);
	// std::cout << i << " : (" << p.first << ", " << p.second << ")\n";
	// }

	for (int i = 1; i < 71; i++)
	{
		honeynest.printCoord(i);
		// std::cout << i << ' ' << honeynest.ring_number(i) << '\n';
		// honeynest.printDistance(1, i);
		// if (i == 14 || i == 40 || i == 44 || i == 50 || i == 52)
		// honeynest.printCoord(i);
	}
	// honeynest.printCoord(10);
	// honeynest.printDistance(13, 30);
	// honeynest.printDistance(13, 50);

	// honeynest.printDistance(1, 10000);
	// honeynest.printDistance(10000, 5);

	// honeynest.printDistance(53, 66); //9
	// honeynest.printDistance(70, 58); //8
	// honeynest.printDistance(62, 70); //8
	// honeynest.printDistance(66, 53); //9
	// honeynest.printDistance(39, 63); //1
	// honeynest.printDistance(26, 11); //1
	// honeynest.printDistance(1, 7);   //1
	// std::cout << honeynest.ring_number(1) << '\n';
	// std::cout << honeynest.ring_number(2) << '\n';
	// std::cout << honeynest.anchor_coords(1).first << ' ' << honeynest.anchor_coords(1).second << '\n';
	// std::cout << honeynest.anchor_coords(2).first << ' ' << honeynest.anchor_coords(2).second << '\n';
	return 0;
}
