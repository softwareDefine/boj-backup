#include <iostream>
#define mod 10000

using namespace std;

int dp[1000][4][4];
int arr[1000];
int n, k;

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}
	if (!arr[1]) {
		dp[1][1][1] = 1;
		dp[1][2][1] = 1;
		dp[1][3][1] = 1;
	}
	else {
		dp[1][arr[1]][1] = 1;
	}
	for (int i = 2; i <= n; i++) {
		if (!arr[i]) {
			dp[i][1][1] = (((dp[i-1][2][1] + dp[i-1][3][1])%mod + dp[i-1][2][2])%mod+dp[i-1][3][2])%mod;
			dp[i][2][1] = (((dp[i - 1][1][1] + dp[i - 1][3][1])%mod + dp[i - 1][1][2])%mod+ dp[i - 1][3][2])%mod;
			dp[i][3][1] = (((dp[i - 1][2][1]+ dp[i - 1][1][1])%mod + dp[i - 1][2][2])%mod + dp[i - 1][1][2])%mod;
			dp[i][1][2] = dp[i-1][1][1];
			dp[i][2][2] = dp[i-1][2][1];
			dp[i][3][2] = dp[i-1][3][1];
		}
		else {
			for (int j = 1; j <= 3; j++) {
				if (j != arr[i]) {
					dp[i][arr[i]][1] =((dp[i-1][j][1]+dp[i-1][j][2])%mod+dp[i][arr[i]][1])%mod;
				}
			}
			dp[i][arr[i]][2] = (dp[i-1][arr[i]][1]+dp[i][arr[i]][2])%mod;
		}
	}
	cout << (((((dp[n][1][1] + dp[n][1][2])%mod + dp[n][2][1])%mod + dp[n][2][2])%mod + dp[n][3][1])%mod + dp[n][3][2])%mod;
}
