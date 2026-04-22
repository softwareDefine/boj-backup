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
	cin >> m >> s;
	if (m * 7 == s * 13) {
		cout << "lika";
	}
	else if (m * 7 > s * 13) {
		cout << "Axel";
	}
	else {
		cout << "Petra";
	}
}