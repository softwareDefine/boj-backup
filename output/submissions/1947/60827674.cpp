#include <iostream>
#define mod 1000000000

using ll = long long;
using namespace std;

ll n;
ll dp[1000100];

int main()
{
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 9;
	for (int i = 5;i <= 1000000;i++) {
		dp[i] = ((i-1)*(dp[i - 1] + dp[i - 2]) % mod)%mod;
	}
	cin >> n;
	cout << dp[n];
}