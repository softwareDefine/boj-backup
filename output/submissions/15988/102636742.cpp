#define mod 1000000009
#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint T;

void solve(){
    int n;
    int dp[110000] = {0, };
    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 1; i <= n; i++){
        dp[i+1] = (dp[i+1]%mod + dp[i]%mod)%mod;
        dp[i+2] = (dp[i+2]%mod + dp[i]%mod)%mod;
        dp[i+3] = (dp[i+3]%mod + dp[i]%mod)%mod;
    }
    cout << dp[n] << '\n';
    return;
}


int main(){
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}