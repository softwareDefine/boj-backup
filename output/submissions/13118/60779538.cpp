#include <iostream>

using namespace std;

long long a, b,c,d;
long long x, y, r;
long long cnt;
int main()
{
	cin >> a >> b >> c >> d;
	cin >> x >> y >> r;
	if (a == x) {
		cout << 1;
	}
	else if (b == x) {
		cout << 2;
	}
	else if (c == x) {
		cout << 3;
	}
	else if(d==x) {
		cout << 4;
	}
	else {
		cout << 0;
	}
		
}