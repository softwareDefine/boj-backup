#include <iostream>

using namespace std;

long long a, b,c,d;
long long x, y, r;
long long cnt;
int main()
{
	cin >> a >> b >> c;
	if (a >= b) {
		cout << 0;
	}
	else {
		if ((b - a) % c == 0) {
			cout << (b - a) / c;
		}
		else {
			cout << (b - a) / c+1;
		}
	}
}