#include <iostream>
#define mod 1000000000

using namespace std;

int n,k;
long long dp[5100][5100];
int main()
{
	cin >> n >> k;
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			for (int a = 0; a <= i; a++) {
					dp[i][j] += dp[i-a][j-1];
					dp[i][j] %= mod;
			}
		}
		
	}
	cout << dp[n][k];
}