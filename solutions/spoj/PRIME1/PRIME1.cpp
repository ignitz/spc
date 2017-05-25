/*
* Yuri Niitsuma
* 2011039023
* http://www.spoj.com/problems/PRIME1/
* PRIME1 - Prime Generator
*/

// Utilizei o Crivo de Eratóstenes e crivo segmentado da dica

#include <iostream>
#include <vector>
#include <cmath>

#define MAX_NUMBERS 10000000

class PrimeTable {
public:
  PrimeTable();
  virtual ~PrimeTable() {};

  void list_bet (long long a, long long b); // a to b

protected:
  std::vector<bool> numbers; // mark prime numbers
  long long max; // max number needed

  std::vector<long long> primes;
};

PrimeTable::PrimeTable () {
  this->max = MAX_NUMBERS;

  // Generate table of prime numbers
  long long max_pos_div = std::sqrt(this->max);
  this->numbers.resize(this->max + 1, 0);

  for (long long i = 2; i <= this->max; i++) {
    numbers[i] = true;
  }

  for (long long i = 2; i <= max_pos_div; i++) {
    if (numbers[i]) {
      // i is prime
      for (long long j = i + i; j <= this->max; j += i) {
        numbers[j] = false; // mark as no prime from table
      }
    }
  }

  // create a array with primes from 2 to 10^7
  primes.push_back(2);
  for (long long i = 3; i <= this->max; i += 2)
    if (numbers[i]) primes.push_back(i);
}

void PrimeTable::list_bet (long long first, long long last) {

  if (last > MAX_NUMBERS) { // Criar crivo segmentado
    std::vector<bool> segmented(last - first, true);
    long long prime;

    for (long long i = 0; i< primes.size(); i++){

      prime = primes[i]*floor(first/primes[i]);
      if (prime < first) prime += primes[i];

      if (primes[i] >= last) break;
      if (primes[i] == prime) continue;

      for (int j = prime; j <= last; j += primes[i]) segmented[j-first] = false;
    }

    for (long long i = 0; i < segmented.size(); i++) {
      if (segmented[i]) {
        std::cout << (first + i) << '\n';
      }
    }
  }
  else { // crivo normal
    for (auto const x : primes) {
      if (x < first) continue;
      if (x > last) break;
      std::cout << x << '\n';
    }
  }
}

class Pair {
public:
  long long init;
  long long end;

  Pair (long long a, long long b) {
    this->init = a;
    this->end = b;
  }
  virtual ~Pair() {}
};

int main(){
  int n; // 1 to 10
  std::vector<Pair> requests;
  long long max_number = 0; // to store max number need
  std::cin >> n;

  long long a, b;

  for (int i = 0; i < n; i++) {
    std::cin >> a >> b;
    requests.push_back(Pair(a, b));
  }

  PrimeTable primes;

  for (auto const req : requests) {
    primes.list_bet(req.init, req.end);
    std::cout << std::endl;
  }

  return 0;
}
