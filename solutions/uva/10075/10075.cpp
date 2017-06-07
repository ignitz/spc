/*
 * Yuri Niitsuma
 * 2011039023
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1016
 * 10075 - Airlines
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

# define M_PI 3.14159265358979323846  /* pi */

class City {
private:
	std::string name;

public:
	double lt, ln; // latitude and longitude

	City (std::string name, double lt, double ln) {
		this->name = name;
		this->lt = lt;
		this->ln = ln;
	}
	virtual ~City () {};

	std::string get_name () { return name; };
};

class MrWorld {
private:
	int n;
	std::vector<City> cities;
	std::vector<std::vector<long long>> direct_flights;
	std::vector<std::vector<long long>> cost_matrix;

	// for floyd_marshall
	bool floyd_done;

public:
	MrWorld (int n) {
		this->n = n;
		direct_flights.resize (n + 1, std::vector<long long> (n + 1, 0));
		floyd_done = false;
	};
	virtual ~MrWorld () {};

	void add_city (City c) {
		cities.push_back(c);
	};

	int calc_dist (int index1, int index2) {
		using namespace std;

		double phi1 = M_PI * (cities[index1].lt/180);
		double phi2 = M_PI * (cities[index2].lt/180);
		double lambda = M_PI * (cities[index1].ln/180 - (cities[index2].ln/180));
		double sigma = acos (sin (phi1) * sin (phi2) + cos (phi1) * cos (phi2) * cos (lambda) );
		return (int) (6378 * sigma + 0.5);
	}

	bool add_direct_flight (std::string name1, std::string name2) {
		int chk = 0;
		int index1, index2;
		for (int i = 0; i < cities.size(); i++) {
			if (name1.compare (cities[i].get_name()) == 0) {
				index1 = i;
				chk++;
			}
			if (name2.compare (cities[i].get_name()) == 0) {
				index2 = i;
				chk++;
			}
			if (chk == 2)
				break;
		}

		if (chk < 2)
			return false;

		direct_flights[index1 +1][index2 + 1] = calc_dist (index1, index2); // calc dist
		return true;
	};

	long long check_distance (std::string name1, std::string name2) {
		int chk = 0;
		int index1, index2;
		for (int i = 0; i < cities.size(); i++) {
			if (name1.compare (cities[i].get_name()) == 0) {
				index1 = i;
				chk++;
			}
			if (name2.compare (cities[i].get_name()) == 0) {
				index2 = i;
				chk++;
			}
			if (chk == 2)
				break;
		}
		if (chk < 2)
			return LLONG_MAX;

		return cost_matrix[index1 + 1][index2 + 1];
	}

	/*
	 * Utilizei o algoritmo feito no ENGARRAF do SPOJ.
	 * o índice vai de 1 a n.
	*/
	void floyd_marshall() {
	  if (this->floyd_done) return;

	  this->floyd_done = true;

	  this->cost_matrix.resize(this->n + 1);

	  for (auto& x : this->cost_matrix) {
	    x.resize(this->n + 1, LLONG_MAX);
	  }

	  for (long long i = 1; i <= this->n; i++) {
	    for (long long j = 1; j <= this->n; j++) {
	      if (this->direct_flights[i][j] != 0) {
	        this->cost_matrix[i][j] = this->direct_flights[i][j];
	      }
	      this->cost_matrix[i][i] = 0;
	    }
	  }

	  long long aux1, aux2;

	  for (long long k = 1; k <= this->n; k++) {
	    for (long long i = 1; i <= this->n; i++) {
	      for (long long j = 1; j <= this->n; j++) {
	        aux1 = (this->cost_matrix[i][j] == LLONG_MAX) ? LLONG_MAX : this->cost_matrix[i][j];
	        aux2 = (this->cost_matrix[i][k] == LLONG_MAX || this->cost_matrix[k][j] == LLONG_MAX) ? LLONG_MAX : this->cost_matrix[i][k] + this->cost_matrix[k][j];
	        this->cost_matrix[i][j] = std::min(aux1, aux2);
	      }
	    }
	  }
	  return;
	};

	void print_matrix () {
		for (int i = 1; i < cost_matrix.size(); i++) {
			for (int j = 1; j < cost_matrix.size(); j++) {
				std::cout << cost_matrix[i][j] << ' ';
			}
			std::cout << '\n';
		}
	};
};

int main(int argc, char const *argv[]) {
	int n, m, q;
	// input vars
	std::string city_name, another_city_name;
	double aux1, aux2;

	int count_case = 1;

	while (std::cin >> n >> m >> q) {
		if ( !(n | m | q) ) break;
		if (count_case > 1) std::cout << '\n';

		MrWorld world(n);

		while (n--) { // read cities
			std::cin >> city_name >> aux1 >> aux2;
			world.add_city(City (city_name, aux1, aux2));
		}

		while (m--) { // read direct flights
			std::cin >> city_name >> another_city_name;
			world.add_direct_flight(city_name, another_city_name);
		}

		world.floyd_marshall();
		std::cout << "Case #" << count_case++ << '\n';
		while (q--) { // read queries
			std::cin >> city_name >> another_city_name;
			long long temp = world.check_distance(city_name, another_city_name);
			if ( temp != LLONG_MAX ) {
				std::cout << temp << " km" << '\n';
			}
			else {
				std::cout << "no route exists" << '\n';
			}
		}
		// DEBUG
		// world.print_matrix();
	}
	return 0;
}
