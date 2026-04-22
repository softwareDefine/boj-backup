#include <iostream>

using namespace std;
int n, m;
int dp[210][210];
int s[20010], e[20010], l[20010];
int mmn = 999999999;

int main()
{
	for (int i = 0; i < 210; i++) {
		for (int j = 0; j < 210; j++) {
			dp[i][j] = 999999999;
		}
		dp[i][i] = 0;
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> s[i] >> e[i] >> l[i];
		dp[s[i]][e[i]] = min(dp[s[i]][e[i]], l[i]);
		dp[e[i]][s[i]] = min(dp[e[i]][s[i]], l[i]);
	}
	for (int k = 1; k <= n; k++) {for (int i = 1; i <= n; i++) {for (int j = 1; j <= n; j++) {dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);}}}
	for (int i = 1; i <= n; i++) {
		int mmx = 0;
		for (int j = 0; j < m; j++) {
			mmx = max(dp[i][s[j]]+dp[i][e[j]]+l[j], mmx);
		}
		mmn = min(mmn, mmx);
	}
	cout << mmn / 2 << '.' << ((mmn % 2)?'5':'0');
}