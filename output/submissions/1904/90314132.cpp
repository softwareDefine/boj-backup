#define fastio cin.tie(0)->sync_with_stdio(0)
#define mod 15746
#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1100000];

int main(){
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=1000000;i++){
        dp[i] = (dp[i-2] + dp[i-1])%mod;
    }
    cout << dp[n];
}