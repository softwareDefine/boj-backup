#include <iostream>
#include <string>

using namespace std;
long long a, b, c;
int main()
{
	cin >> a >> b >> c;
	if (a == b && b == c) {
		cout << 10000 + a * 1000;
	}
	else if (a == b || b == c || a==c) {
		if (a == b) {
			cout << 1000 + a * 100;
		}
		else if(a== c) {
			cout << 1000 + a * 100;
		}
		else {
			cout << 1000 + b * 100;
		}
	}
	else {
		cout << 100*max(a, max(b, c));
	}
}