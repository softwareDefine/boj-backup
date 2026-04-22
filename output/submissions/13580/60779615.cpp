#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;
int a, b,c;
int main(void) {
	cin >> a >> b >> c;
	if (a == b || b == c || a == c || a + b == c || a + c == b || a == b + c) {
		cout << "S";
	}
	else {
		cout << "N";
	}
}