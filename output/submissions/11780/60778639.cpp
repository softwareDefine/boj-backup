#include <iostream>
#include <vector>
#define inf 100001000

using namespace std;

int n, m;
int check[101][101];

int dp[101][101];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i < 101; i++) {
		for (int j = 1; j < 101; j++) {
			if (i == j) {
				continue;
			}
			dp[i][j] = inf;
		}
	}
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		dp[start][end] = min(cost,dp[start][end]);
		check[start][end] = end;
	}
	for(int k=1;k<=n;k++){
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dp[i][j] > dp[i][k] + dp[k][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
					check[i][j] = check[i][k];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == inf) { cout << '0' << ' '; continue; }
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	int cnt = 1;
	int now = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				cout << "0" << '\n';
				continue;
			}
			cnt = 1;
			now = i;
			while (now!=j) {
				now = check[now][j];
				cnt++;
				if (cnt > 100000) {
					break;
				}
			}
			if (cnt > 100000) {
				cout << "0" << '\n';
			}
			else {
				cout << cnt << ' ';
				now = i;
				cout << now << ' ';
				while (now != j) {
					now = check[now][j];
					cout << now << ' ';
				}
				cout << '\n';
			}
		}
	}
}