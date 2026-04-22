#include <iostream>

using namespace std;

int n,sum;
int main()
{
	cin >> n;
	int i = 1;
	for (i; sum <= n; i++) {
		sum += i;
	}
	if (i % 2 == 1) {
		cout << 0;
	}
	else {
		cout << sum - n;
	}
}