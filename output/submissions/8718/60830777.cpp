#include <iostream>

using namespace std;

long long a, b,c,d;
long long x, y, z;
long long cnt;
int main()
{
	cin >> b >> a;
	if (7000 * a <= 1000 * b) {
		x = 7000 * a;
	}
	if (3500 * a <= 1000 * b) {
		y = 3500 * a;
	}
	if (1750 * a <= 1000 * b) {
		z = 1750 * a;
	}
	cout << max(max(x, y), z);
}