#include <iostream>

using ll = long long;
using namespace std;

int t;
int n, m;
ll dp[15][5010];
ll cnt;
int main()
{
	cin >> t;
	while (t--) {
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 5010; j++) {
				dp[i][j] = 0;
			}
		}
		cnt = 0;
		cin >> n >> m;
		for (int i = 1; i <= m; i++) { dp[1][i] = 1; }
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j*2 <= m; j++) {
				for (int k = 0;  j*2+k <= m; k++) {
					dp[i + 1][j * 2 + k] += dp[i][j];
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			cnt += dp[n][i];
		}
		cout << cnt << '\n';
	}
}