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
	cin >> r;
	a = r * 0.01 + 25;
	if (a < 100) {
		a = 100;
	}
	else if (a>2000) {
		a = 2000;
	}
	printf("%.1000lf", a);
}