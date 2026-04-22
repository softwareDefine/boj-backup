#include <iostream>
#include <algorithm>

using namespace std;

int a;
int main()
{
	cin >> a;
	int sum = a * 5 - 400;
	cout << sum << '\n';
	if (sum > 100) {
		cout << -1;
	}
	else if (sum < 100) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}