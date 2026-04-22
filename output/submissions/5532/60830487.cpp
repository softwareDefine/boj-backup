#include <iostream>

using namespace std;

int a,b,c,d,e;
int sum;

int main()
{
	cin >> a >> b >> c >> d >> e;
	if (b % d == 0) {
		sum = b / d;
	}
	else {
		sum = b / d + 1;
	}
	if (c % e == 0) {
		sum = max(c / e,sum);
	}
	else {
		sum = max(c / e + 1,sum);
	}
	cout << a-sum;
}
