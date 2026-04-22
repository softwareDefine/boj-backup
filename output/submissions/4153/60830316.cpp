#include <iostream>

using namespace std;

int main()
{
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		if(b > a && b > c) {
			swap(a,b);
		}
		else if (c > a && c > b) {
			swap(c, a);
		}
		if (b < c) {
			swap(b, c);
		}
		if (a * a == b * b + c * c) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}
}