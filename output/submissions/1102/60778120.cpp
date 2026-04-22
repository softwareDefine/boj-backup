#include <iostream>

using ll = long long;
using namespace std;

ll dp[65536];
ll w[17][17];
ll n,m;
ll cnt;
ll mmn = 999999999;
string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}
	cin >> str;
	cin >> m;
	for (int k = 0; k < (1 << n); k++) {
		dp[k] = 999999999;
	}
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'Y') {
			cnt += (1 << i);
		}
	}
	dp[cnt] = 0;
	for (int alpha = 0; alpha < 100; alpha++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < (1 << n); k++) {
					if ((k & (1 << i)) == 0) { continue; }
					dp[k | (1 << j)] = min(dp[k | (1 << j)], dp[k] + w[i][j]);
				}
			}
		}
	}
	for (int i = 0; i < (1<<n); i++) {
		cnt = 0;
		for (int j = n-1; j >=0 ; j--) {
			if ((1 << j) & i) {
				cnt++;
			}
		}
		if (cnt >= m) {
			mmn = min(dp[i], mmn);
		}
	}
	if (mmn == 999999999) {
		cout << "-1";
	}
	else {
		cout << mmn;
	}
}