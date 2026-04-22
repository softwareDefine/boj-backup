#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
int sum;
int a, b, c;
    int d, e, f;
int main(void) {
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    if (d - a > 0) {
        sum += d - a;
    }
    if (e - b > 0) {
        sum += e - b;
    }
    if (f - c > 0) {
        sum += f - c;
    }
    cout << sum;
}