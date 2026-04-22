#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
int sum;
int a, b, c, d;
int main(void) {
    cin >> a >> b >> c >> d;
    if ((a == 8 || a == 9) && (b == c) && (d == 8 || d == 9)) {
        cout << "ignore";
    }
    else {
        cout << "answer";
    }
}