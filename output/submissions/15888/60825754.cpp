#include <iostream>
#include <cmath>

using namespace std;

long long a, b, c;

int main()
{
	cin >> a >> b >> c;
	if (b * b - 4 * a * c <= 0) {
		cout << "둘다틀렸근";
	}
	else {
		long double one = (-b + sqrt(b * b - 4 * a * c)) / double(2 * a);
		long double two = (-b - sqrt(b * b - 4 * a * c)) / double(2 * a);
		if ((long long)one == one && (long long)two == two) {
			long long ione = one;
			long long itwo = two;
			bool err = 0;
			if (ione == 1 || ione <= 0) {
				err = 1;
			}
			while (ione) {
				if (ione == 1) {
					break;
				}
				if (ione % 2 == 1 && ione!=1) {
					err = 1;
					break;
				}
				ione /= 2;
			}
			if (itwo == 1 || itwo <=0) {
				err = 1;
			}
			while (itwo) {
				if (itwo == 1) {
					break;
				}
				if (itwo % 2 == 1 ) {
					err = 1;
					break;
				}
				itwo /= 2;
			}
			if (err) {
				cout << "정수근";
			}
			else {
				cout << "이수근";
			}
		}
		else {
			cout << "둘다틀렸근";
		}
	}
}