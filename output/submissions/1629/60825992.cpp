#include <iostream>

using namespace std;

unsigned long long c, n,a;

unsigned long long def(unsigned long long c, unsigned long long n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return c % a;
    }
    unsigned long long res = def(c, n / 2) % a;
    if (n % 2 == 1) {
        return (((res * res)%a)*c)%a;
    }
    else {
        return (res * res) %a;
    }
}

int main()
{
    cin >> c >> n >> a;
    cout << def(c, n) % a;
}
