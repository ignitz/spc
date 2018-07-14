#include <iostream>

// https://www.urionlinejudge.com.br/judge/pt/problems/view/1047

struct TimeLen
{
    int hour;
    int minute;
    int timestamp;
};

TimeLen start_time, end_time;

using namespace std;

int get_timestamp(TimeLen &aux_time)
{
    return aux_time.hour * 60 + aux_time.minute;
}

void get_back_hour_min(TimeLen &aux_time)
{
    aux_time.hour = aux_time.timestamp / 60;
    aux_time.minute = aux_time.timestamp % 60;
}

int main()
{
    cin >> start_time.hour >> start_time.minute;
    cin >> end_time.hour >> end_time.minute;

    start_time.timestamp = get_timestamp(start_time);
    end_time.timestamp = get_timestamp(end_time);

    TimeLen result;

    if (start_time.timestamp < end_time.timestamp)
    {
        result.timestamp = end_time.timestamp - start_time.timestamp;
    }
    else if (start_time.timestamp == end_time.timestamp)
    {
        result.timestamp = 24 * 60;
    }
    else
    {
        result.timestamp = end_time.timestamp + 24 * 60 - start_time.timestamp;
    }

    get_back_hour_min(result);

    cout << "O JOGO DUROU " << result.hour << " HORA(S) E " << result.minute << " MINUTO(S)\n";

    return 0;
}