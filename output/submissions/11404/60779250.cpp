#include <iostream>
#define inf 10000000000

using ll = long long;
using namespace std;

int n,m;
ll dp[110][110];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < 110; i++) {
		for (int j = 0; j < 110; j++) {
			if (i == j) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = inf;
		}
	}
	for (int i = 0; i < m; i++) {
		ll start, end, cost;
		cin >> start >> end >> cost;
		dp[start][end] = min(cost,dp[start][end]);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dp[i][j] > dp[i][k] + dp[k][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == inf) {
				cout << '0' << ' ';
				continue;
			}
			cout <<  dp[i][j] << ' ';
		}
		cout << '\n';
	}
}