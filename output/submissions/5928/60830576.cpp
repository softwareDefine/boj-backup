#include <iostream>
#define minus 16511

using namespace std;

int day,hour,minute;
int main()
{
    cin >> day >> hour >> minute;
    if (day * 60 * 24 + hour * 60 + minute < minus) {
        cout << "-1";
    }
    else {
        cout << day * 60 * 24 + hour * 60 + minute - minus;
    }
}
