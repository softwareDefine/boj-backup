#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int m, s, g, l, r;
double a, b;
int arr[3];
int main()
{
	cin >> m >> s >> g;
	cin >> a >> b;
	cin >> l >> r;
	int x, y;
	if (m % g ==0) {
		 x = m / g;
	}
	else {
		 x = m / g + 1;
	}
	if (m % s == 0) {
		 y = m / s;
	}
	else {
		 y = m / s + 1;
	}
	if (x < y) {
		if (x + l / a < y + r / b) {
			cout << "friskus";
		}
		else {
			cout << "latmask";
		}
	}
	else {
		if (x + l / a < y + r / b) {
			cout << "friskus";
		}
		else {
			cout << "latmask";
		}
	}
}