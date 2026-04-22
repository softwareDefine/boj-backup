#include <iostream>
#include <math.h>

using ll = long long;
using namespace std;

ll arr[50][50];
ll cnt;
ll mmxlen;
int r1, c1, r2, c2;
ll check(int y, int x) {
	ll cnt = max(abs(y), abs(x));
	pair<int, int> base = {cnt - 1, cnt};
	ll start = pow(cnt * 2 - 1, 2) + 1;
	if (cnt == 0) { return 1; }
	if (y == -cnt) {
		return start + base.second -y + base.first -x;
	}
	else if (y == cnt) {
		return pow((cnt + 1) * 2 - 1, 2) -(base.second-x);
	}
	else if (x == cnt) {
		return start + (base.second - y-1);
	}
	else if (x == -cnt) {
		return pow((cnt + 1) * 2 - 1, 2) - (base.second - y+1 + base.first - x);
	}
}

int main()
{
	cin >> r1 >> c1 >> r2 >> c2;
	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			arr[i - r1][j - c1] = check(i, j);
			ll chk = arr[i - r1][j - c1];
			cnt = 0;
			while (chk) {
				chk /= 10;
				cnt++;
			}
			mmxlen = max(cnt, mmxlen);
		}
	}
	for (int i = r1; i <= r2; i++) {
		
		for (int j = c1; j <= c2; j++) {cnt = 0;
			ll chk = arr[i - r1][j - c1];
			while (chk) {
				chk /= 10;
				cnt++;
			}
			for (int k = 0; k < mmxlen - cnt; k++) {
				cout << ' ';
			}
			cout << arr[i - r1][j - c1] << ' ';
		}
		cout << '\n';
	}
}