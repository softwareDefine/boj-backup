#include <iostream>

using namespace std;

int n;

int main()
{
	cin >> n;
	cout << "Gnomes:" << '\n';
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if ((a >=b) &&(b >= c) || (a<=b) && (b <=c)) {
			cout << "Ordered" << '\n';
		}
		else {
			cout << "Unordered" << '\n';
		}
	}
}