#define mod 10007
#include <iostream>

using namespace std;
long long dp[1010][2];
int n;

int main()
{
	cin >> n;
	dp[0][1] = 1;
	dp[1][0] = 1;
	dp[1][1] = 0;
	dp[2][1] = 1;
	dp[2][0] = 1;
	dp[3][0] = dp[2][0]+dp[2][1];
	dp[3][1] = dp[2][0];
	for (int i = 4; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	cout << dp[n - 1][0]+dp[n-1][1];
}