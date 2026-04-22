#define mod 10007
#include <bits/stdc++.h>

using namespace std;

int n;

int dp[1200][10];

int ans; 

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    dp[0][0] = 1;
    for(int i = 1; i <= 1000; i++){
        for(int j = 0; j <= 9; j++){
            for(int k = 0; k <= j; k++){
                dp[i][j] = (dp[i][j]%mod + dp[i-1][k]%mod)%mod;
            }
        }
    }
    for(int i = 0; i <= 9; i++){
        ans = (ans%mod + dp[n][i]%mod)%mod;
    }
    cout << ans;
	return 0;
}