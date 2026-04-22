#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
long long sum;
int a, b, c;
    int d, e, f;
int main(void) {
    while (1) {
        cin >> a;
        if (a == -1) {
            break;
        }
        sum += a;
    }
    cout << sum;
}