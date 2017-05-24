/*
 * Yuri Niitsuma
 * 2011039023
 * http://br.spoj.com/problems/ONZE/
 * ONZE
*/

#include <iostream>
#include <string>

bool check_multiple (std::string number) {
    bool impar = true;
    long long sum = 0;
    for (auto c : number) {
        sum += (impar) ? atoi(&c) : -atoi(&c);
        impar = !impar;
    }
    return !(sum % 11);
}

int main(){
    std::string number;
    while (true) {
        std::cin >> number;
        if (number[0] == '0' && number.size() == 1)
            break;
        std::cout << number << " is ";
        // check if multiple
        if (!check_multiple (number)) {
            std::cout << "not ";
        }
        std::cout << "a multiple of 11." << std::endl;
    }
	return 0;
}
