#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(void) {
    int a, b;string s;
    cin >> a;
    scanf("\n");
    for (int i = 1; i <= a; i++) {
        getline(cin, s);
        cout << i << ". " << s << '\n';
    }
    return 0;
}