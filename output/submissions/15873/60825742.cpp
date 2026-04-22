#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int a;
int main()
{
	cin >> a;
	if (a / 10 == 0) {
		cout << a;
	}
	else if (a % 1010 == 0) {
		cout << 20;
	}
	else if (a / 100 > 0) {
		if (a / 100 == 1) {
			cout << a / 10 + a % 10;
		}
		else {
			cout << a % 100 + a / 100;
		}
	}
	else {
		cout << a / 10 + a % 10;
	}
}