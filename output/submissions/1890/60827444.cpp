#include <iostream>

using ll = long long;
using namespace std;
ll arr[1100][1100];
ll dp[1100][1100];
int n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > 0) {
				dp[i + arr[i][j]][j] += dp[i][j];
				dp[i][j + arr[i][j]] += dp[i][j];
			}
		}
	}
	cout << dp[n - 1][n - 1];
}