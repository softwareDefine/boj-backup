#include <iostream>

using namespace std;

int a, b;

int main() {
	cin >> a >> b;
	if (b - 45 < 0) {
		a -= 1;
		b += 60;
		b -= 45;
	}
	else {
		b -= 45;
	}
	if (a < 0) {
		a = 23;
	}
	cout << a <<' '<< b;
}