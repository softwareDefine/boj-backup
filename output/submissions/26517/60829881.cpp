#include <iostream>

using ll = long long;
using namespace std;

ll n;
ll a, b, c, d;
int main()
{
	cin >> n;
	cin >> a >> b >> c >> d;
	if (a * n + b == c * n + d) {
		cout << "Yes" << ' ' << a * n + b;
	}
	else {
		cout << "No";
	}
}