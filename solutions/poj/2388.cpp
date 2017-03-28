/*
 * Yuri Diego Santos Niitsuma
 * 2011039023
 * Link: http://poj.org/problem?id=2388
 * ID: PKU_2388
 */

#include <iostream>
#include <vector>
#include <algorithm>

int get_mediana(std::vector<int> lines) {
    int size = lines.size();
    if (size % 2) {
        return lines[size/2];
    }
    else {
        return (lines[size/2] + lines[size/2 -1])/2;
    }
}

int main(int argc, char *argv[]) {
    using namespace std;
    int n;
    int input;
    cin >> n;

    vector<int> lines;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        lines.push_back(input);
    }
    sort(lines.begin(), lines.end());
    cout << get_mediana(lines) << endl;
    return 0;
}
