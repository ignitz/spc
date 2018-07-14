#include <iostream>

// https://www.urionlinejudge.com.br/judge/pt/problems/view/1046

using namespace std;
 
int main()
{
    int start_hour, end_hour, total;
    cin >> start_hour;
    cin >> end_hour;

    if (start_hour < end_hour)
        total = end_hour - start_hour;
    else if (start_hour == end_hour)
        total = 24;
    else
        total = end_hour + 24 - start_hour;

    cout << "O JOGO DUROU " << total << " HORA(S)\n";

    return 0;
}