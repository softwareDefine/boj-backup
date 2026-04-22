#include <iostream>
#include <math.h>

using namespace std;

long long a, b, c;
double l, r;
double f(double x) {
    return a * x + b * sin(x) - c;
}

int main()
{
    cin >> a >> b >> c;
    l = 0;
    r = pow(10, 6);
    double mid = (l + r) / 2;
    while (abs(r - l) >= pow(10, -9)) {
        if (f(mid) > 0) {
            r = mid;
        }
        else {
            l = mid;
        }
        mid = (l + r) / 2;
    }
    printf("%.1000lf", mid);
}