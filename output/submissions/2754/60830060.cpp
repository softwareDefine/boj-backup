#include <iostream>
#include <string>
#include <string.h>

using namespace std;

double n =0.0;
int main()
{
	string a;
	cin >> a;
	cout << fixed;
	cout.precision(1);
	if (a[0] == 'A') {
		n += 4.0;
	}
	else if(a[0]=='B') {
		n += 3.0;
	}
	else if (a[0] == 'C') {
		n += 2.0;
	}
	else if (a[0] == 'D') {
		n += 1.0;
	}
	else {
		cout << 0.0;
		goto one;
	}
	if (a[1] == '+') {
		n += 0.3;
	}
	else if(a[1] == '-') {
		n -= 0.3;
	}
	else {

	}
	cout << n;
		one:
	return 0;
}