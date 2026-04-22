#include <iostream>
#include <math.h>

using namespace std;
long long n, m, a, k;
int main()
{
    cin >> n >> m >> a >> k;
    cout << min((a - k) + 1, n) << ' ';
    if ((a - k) % m == 0) {
        cout << (a - k) / m+1;
    }
    else {
        cout << (a - k) / m+2;
    }
}