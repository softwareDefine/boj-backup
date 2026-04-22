#include <iostream>

using namespace std;

int n, m;
int arr[1010][1010];
int dp[1010][1010];
int mmx;
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
			if (i - 1 >= 0 && j - 1 >= 0) {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i][j]);
			}
			if (i-1>=0) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j]);
			}
			if (j - 1 >= 0) {
				dp[i][j] = max(dp[i][j - 1], dp[i][j]);
			}
			dp[i][j] += arr[i][j];
			mmx = max(dp[i][j], mmx);
		}
	}
	cout << mmx;
}