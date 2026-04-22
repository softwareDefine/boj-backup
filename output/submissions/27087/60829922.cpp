#include <iostream>

using namespace std;
int t;
int main()
{
	cin >> t;
	while (t--) {
		int x, y, z, p;
		int cnt = 0;
		cin >> x >> y >> z >> p;
		if (x / p != 0 && x % p == 0 ) {
			cnt++;
		}
		if (y / p != 0 && y % p == 0) {
			cnt++;
		}
		if (z/p!=0 && z%p==0) {
			cnt++;
		}
		if (cnt >= 2) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
}