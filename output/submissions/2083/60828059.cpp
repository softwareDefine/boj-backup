#include <iostream>
#include <string>

using namespace std;

int main()
{
	while (1) {
		string a;
		int b, c;
		cin >> a >> b >> c;
		if (a[0] == '#' && b == 0 && c == 0) {
			break;
		}
		cout << a << ' ';
		if (b > 17 || c >= 80) {
			cout << "Senior" << '\n';
		}
		else {
			cout << "Junior" << '\n';
		}
	}
}