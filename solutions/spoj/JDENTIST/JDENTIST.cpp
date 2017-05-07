/*
 * Yuri Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/JDENTIST/
 * JDENTIST
 */

// O alg guloso que escolhe sempre a tarefa que termina primeiro

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

bool mycomp(const std::pair<int, int> & a, const std::pair<int, int> & b) {
  return std::get<1>(a) < std::get<1>(b);
}

int main(){
	int n;
  int init, end;

  std::vector<std::pair<int,int>> vec;

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> init >> end;
    vec.push_back(std::make_pair(init, end));
  }
  std::sort(vec.begin(), vec.end(), mycomp);

  int aux_end = 0;
  int count = 0;

  for (int i = 0; i < vec.size(); i++) {
    if (aux_end <= std::get<0>(vec[i])) {
      aux_end = std::get<1>(vec[i]);
      count++;
    }
  }

  std::cout << count << '\n';

  return 0;
}
