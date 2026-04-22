#include <iostream>

using namespace std;

int n;
int dp[110][110];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> dp[i][j];
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = max((int)(dp[i][k] && dp[k][j]),dp[i][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
}