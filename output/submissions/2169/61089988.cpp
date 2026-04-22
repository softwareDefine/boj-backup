#include <iostream>

using ll = long long;

using namespace std;
bool visited[1010][1010];
ll dpfirst[1010][1010];
ll dpsecond[1010][1010];
ll dp[1010][1010];
ll arr[1010][1010];
int n,m;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			dpfirst[i][j] = -99999999999;
			dpsecond[i][j] = -9999999999;
		}
	}
	dpfirst[0][0] = 0;
	dpsecond[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dpfirst[i][j + 1] = max(dpfirst[i][j] + arr[i][j], dpfirst[i][j + 1]);
		}
		if (i != 0) {
			for (int j = m - 1; j >= 0; j--) {
				if (j != 0) {
					dpsecond[i][j - 1] = max(dpsecond[i][j] + arr[i][j],dpsecond[i][j-1]);
				}
			}
		}
		for (int j = m - 1; j >= 0; j--) {
			dp[i][j] = max(dpfirst[i][j], dpsecond[i][j]);
			dpfirst[i + 1][j] = dp[i][j] + arr[i][j];
			visited[i + 1][j] = 1;
			dpsecond[i + 1][j] = dp[i][j] + arr[i][j];
		}
	}
	cout << dp[n - 1][m - 1] + arr[n - 1][m - 1];
}