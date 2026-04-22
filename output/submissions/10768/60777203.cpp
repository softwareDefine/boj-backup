#include <iostream>
#include <math.h>
#include <string.h>
#include <string>

using namespace std;

int a,b,c,d,e;
int suma,sumb;

int main()
{
	cin >> a >> b;
	if (a > 2) {
		cout << "After";
	}
	else if (a < 2) {
		cout << "Before";
	}
	else {
		if (b < 18) {
			cout << "Before";
		}
		else if (b == 18) {
			cout << "Special";
		}
		else {
			cout << "After";
		}
	}
}