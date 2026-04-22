#include <iostream>

using namespace std;

int dp[22][22][22];

int a;
int n;
int s, e;
int arr[1001010];
int szze;
int mmn = 99999999;

int main()
{
	cin >> n;
	cin >> s >> e;
	cin >> szze;
	for (int i = 1; i <= szze; i++) {
		cin >> arr[i];
	}
	if (s > e) {
		s ^= e;
		e ^= s;
		s ^= e;
	}
	for (int i = 0; i <= szze; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				dp[i][j][k] = 9999999;
			}
		}
	}
	dp[1][arr[1]][e] = dp[1][e][arr[1]] = abs(s - arr[1]);
	dp[1][arr[1]][s] = dp[1][s][arr[1]] = abs(e - arr[1]);
	for (int i = 1; i <= szze; i++) {
			for (int k = 1; k <= n; k++) {
				dp[i + 1][arr[i+1]][k] = min(dp[i][arr[i]][k]+abs(arr[i]-arr[i+1]),dp[i+1][arr[i+1]][k]);
				dp[i + 1][arr[i + 1]][arr[i]] = min(dp[i][k][arr[i]] + abs(k - arr[i + 1]), dp[i + 1][arr[i + 1]][arr[i]]);
				dp[i + 1][k][arr[i+1]] = min(dp[i][k][arr[i]] + abs(arr[i] - arr[i + 1]), dp[i + 1][k][arr[i+1]]);
				dp[i + 1][arr[i]][arr[i+1]] = min(dp[i][arr[i]][k] + abs(k - arr[i + 1]), dp[i + 1][arr[i]][arr[i + 1]]);
			}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			mmn = min(dp[szze][i][j], mmn);
		}
	}
	cout << mmn;
}