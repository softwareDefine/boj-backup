#include <iostream>

using namespace std;

int n,k,m;
int cnt;

int main()
{
	cin >> k >> n >> m;
	if (k * n <= m) {
		cout << 0;
	}
	else {
		cout << k * n - m;
	}
}
