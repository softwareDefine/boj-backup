#include <iostream>

using namespace std;

int a, b, c;
int main()
{
	cin >> a >> b >> c;
	if (a + b + c < 100) {
		if (a <= b && a <= c) {
			cout << "Soongsil";
		}
		else if (b <= c && b <= a) {
			cout << "Korea";
		}
		else {
			cout << "Hanyang";
		}
	}
	else {
		cout << "OK";
	}
}