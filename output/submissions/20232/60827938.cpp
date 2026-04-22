#include <iostream>
#include <string>

using namespace std;

int n;
int a, b, c;
int main()
{
	cin >> a;
	if (a == 2006) {
		cout << "PetrSU, ITMO";
	}
	else if (a == 1996 || a == 1997 || a == 2000 || a == 2007 || a == 2008 || a == 2013 || a == 2018) {
		cout << "SPbSU";
	}
	else {
		cout << "ITMO";
	}
}