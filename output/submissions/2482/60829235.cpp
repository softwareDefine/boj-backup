#include <iostream>
#define mod 1000000003

using ll = long long;
using namespace std;

ll dp[1100][1100];
ll dp_prime[1100][1100];
ll all[1100][1100];
int n, k;
int main()
{
	dp[3][2] = 0;
	dp[4][0] = 1;
	dp[4][1] = 4;
	dp[4][2] = 2;
	dp[5][0] = 1;
	dp[5][1] = 5;
	dp[5][2] = 5;
	for (int i = 6; i <= 1000; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <=1000; j++) {
			dp[i][j] += (dp[i - 1][j] + dp[i - 2][j - 1])%mod;
		}
	}
	cin >> n >> k;
	cout << dp[n][k];
}