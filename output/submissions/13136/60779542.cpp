#include <iostream>
#define minus 16511

using namespace std;

int a,b,c;
long long sum=1;
int main()
{
    cin >> a >> b >> c;
    if (a % c != 0) {
       sum=a / c + 1;
    }
    else {
        sum=a / c;
    }
    if (b % c != 0) {
        sum *= b / c + 1;
    }
    else {
        sum *= b / c;
    }
    cout << sum;
}
