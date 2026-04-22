#include <iostream>

using namespace std;

long long a, b,c,d;
long long x, y, z;
long long cnt;
int main()
{
	cin >> a >> b >> c;
	if ((a * a == b * b + c * c) || (b * b == a * a + c * c) || (c * c == a * a + b * b) ) {
		cout << 1;
	}
	else if(a == b && b == c) {
		cout << 2;
	}
	else {
		cout << 0;
	}
}