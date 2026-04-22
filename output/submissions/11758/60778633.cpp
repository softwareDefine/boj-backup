#include <iostream>

using namespace std;
int a,b,c,d,e,f;
int main()
{
	cin >> a >>b >>c >>d>>e>>f;
	if (a * d + c * f + e * b - b * c - d * e - f * a <0) {
		cout << "-1";
	}
	else if (a * d + c * f + e * b - b * c - d * e - f * a > 0) {
		cout << "1";
	}
	else {
		cout << "0";
	}

}