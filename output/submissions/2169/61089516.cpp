#include <iostream>

using namespace std;

int dpfirst[1010][1010];
int dpsecond[1010][1010];
int dp[1010][1010];
int arr[1010][1010];
int n,m;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dpfirst[i][j + 1] = max(dpfirst[i][j] + arr[i][j], dpfirst[i][j + 1]);
		}
		if (i != 0) {
			for (int j = m - 1; j >= 0; j--) {
				if (j != 0) {
					dpsecond[i][j - 1] = max(dpsecond[i][j] + arr[i][j], dpsecond[i][j - 1]);
				}
			}
		}
		for (int j = m - 1; j >= 0; j--) {
			dp[i][j] = max(dpfirst[i][j], dpsecond[i][j]);
			dpfirst[i + 1][j] = max(dp[i][j] + arr[i][j], dpfirst[i + 1][j]);
			dpsecond[i + 1][j] = max(dp[i][j] + arr[i][j], dpsecond[i + 1][j]);
		}
	}
	cout << dp[n - 1][m - 1] + arr[n - 1][m - 1];
}