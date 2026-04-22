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
	cin >> m >> s >> g >> l;
	if (g < 0 && l >= 10) {
		cout << "A storm warning for tomorrow! Be careful and stay home if possible!";
	}
	else if (m > g) {
		cout << "MCHS warns! Low temperature is expected tomorrow.";
	}
	else if (s < l) {
		cout << "MCHS warns! Strong wind is expected tomorrow.";
	}
	else {
		cout << "No message";
	}
}