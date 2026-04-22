#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
int sum;
string a, b, c, d;
int main(void) {
    cin >> a;
    for (int i = 0; i < a.length(); i++) {
        a[i] = toupper(a[i]);
    }
    cout << a;
}