#include <iostream>

using namespace std;

long long a, b, c, d, e;
long long timer;
int main()
{
	cin >> a >> b >> c >> d >> e;
	if (a < 0) {
		cout << abs(a) * c + d + b*e;
	}
	else {
		cout << (b - a) * e;
	}
}