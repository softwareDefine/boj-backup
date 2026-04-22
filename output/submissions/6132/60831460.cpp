#include <iostream>

using namespace std;

int arr[100010];
//i까지의 높이가 j일때 최소 높이
int dp[100010][101];
int n, c;
int mmn = 99999999;
int main()
{
	cin >> n >> c;
	for (int i = 0; i < 100010; i++) {
		for (int j = 0; j < 101; j++) {
			dp[i][j] = 99999999;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int z = arr[i]; z <= 100; z++) {
			for (int j = arr[i+1]; j <= 100; j++) {
				if (i == 0) {
					dp[i + 1][j] = min(dp[i][z]  + (j - arr[i + 1]) * (j - arr[i + 1]), dp[i + 1][j]);
				}
				else {
					dp[i + 1][j] = min(dp[i][z] + abs(z - j) * c + (j - arr[i + 1]) * (j - arr[i + 1]), dp[i + 1][j]);
				}

			}
		}
	}
	for (int i = 0; i<=100; i++) {
		mmn = min(dp[n][i],mmn);
	}
	cout << mmn;
}