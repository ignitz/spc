/*
 * Yuri Niitsuma
 * 2011039023
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1028
 * 1028 - Figurinhas
*/

#include <iostream>

// Algoritmo euclidiano
int mdc2 (int a, int b) {
    int r;

    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
    
}


int mdc (int n, int m) {
    int max_div = std::max(n/2, m/2);

    int max_div_common = 1;
    // first find all even numbers
    while ( (n % 2 == 0) && (m % 2 == 0) && n > 0 && m > 0) {
        max_div_common *= 2;
        n /= 2; m /= 2;
    }

    // find all odd numbers
    int i = 3;
    while ( i <= max_div ) {
        if ( (n % i == 0) && (m % i == 0) ) {
            max_div_common *= i;
            n /= i; m /= i;
        }
        else {
            i += 2;
        }
    }
    return max_div_common;
}

int main() {
    int number_of_tests, f1, f2;
    std::cin >> number_of_tests;
    for (int i = 0; i < number_of_tests; i++) {
        std::cin >> f1 >> f2;
        std::cout << mdc2(f1, f2) << std::endl;
    }
	return 0;
}
