#include <iostream>
#include <algorithm>

using namespace std;
int p, n,sum,arr[10000];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int cnt = 0;
		for (int x = 1; x <= a; x++) {
			for (int y = 1; y <= b; y++) {
				for (int z = 1; z <= c; z++) {
					if ((x % y == y % z) && (x % y == z % x)) {
						cnt++;
					}
				}
			}
		}
		cout << cnt << '\n';
	}
}