/*
 * Yuri Diego Santos Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/BRACELMG/
 * BRACELMG
 */

#include <iostream>
#include <algorithm>

bool has_pattern(std::string pattern, std::string word) {
  std::string double_word(word + word);
  size_t pos = double_word.find(pattern);
  if (pos != std::string::npos)
    return true;

  std::reverse(double_word.begin(), double_word.end());
  pos = double_word.find(pattern);
  if (pos != std::string::npos)
    return true;
  else
    return false;
}

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::string word, pattern;

  for (size_t i = 0; i < n; i++) {
    std::cin >> pattern;
    std::cin >> word;
    if (has_pattern(pattern, word)) {
      std::cout << "S" << '\n';
    } else {
      std::cout << "N" << '\n';
    }
  }
  return 0;
}
