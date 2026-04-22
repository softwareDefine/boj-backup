#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;
int a, b;
int main(void) {
	cin >> a >> b;
	if (a <= 50 && b <= 10) {
		cout << "White";
	}
	else if (b >30) {
		cout << "Red";
	}
	else {
		cout << "Yellow";
	}
}