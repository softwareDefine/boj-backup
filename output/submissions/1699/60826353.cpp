#include <iostream>

using namespace std;

int n;
int dp[1000000];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = 999999;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i-j*j]+1,dp[i]);
		}
	}
	cout << dp[n];
}