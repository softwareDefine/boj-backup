#define mod 9901
#include <bits/stdc++.h>

using namespace std;

int n;

int dp[110000][4];

int main() {
    cin >> n;
    dp[0][0] = 1;
    for(int i = 1; i <= n+1; i++){
        dp[i][0] = (dp[i-1][0]%mod + dp[i-1][1]%mod + dp[i-1][2]%mod)%mod;
        dp[i][1] = (dp[i-1][0]%mod + dp[i-1][2]%mod)%mod;
        dp[i][2] = (dp[i-1][0]%mod + dp[i-1][1]%mod)%mod;
    }
    cout << dp[n+1][0];
	return 0;
}