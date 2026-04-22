#include <iostream>
#include <vector>

using namespace std;

char a;
int cnt;

int main()
{
	for (int i = 0; i < 6; i++) {
		cin >> a;
		if (a == 'W') {
			cnt++;

		}
	}
	if (cnt == 5 || cnt == 6) {
		cout << 1;
	}
	else if (cnt >= 3) {
		cout << 2;
	}
	else if (cnt >= 1) {
		cout << 3;
	}
	else {
		cout << -1;
	}
}