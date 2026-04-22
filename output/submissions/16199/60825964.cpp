#include <iostream>

using namespace std;

int n;
int a, b, c, d, e, f;
int main()
{
	cin >> a >> b >> c;
	cin >> d >> e >> f;
	if (b < e || ((e == b) && (c <= f))) {
		cout << d - a << '\n';
	}
	else {
		cout << d - a - 1 << '\n';
	}
	cout << d - a+1 << '\n';
	cout << d - a << '\n';
}