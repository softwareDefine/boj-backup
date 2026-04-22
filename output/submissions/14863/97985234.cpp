#include <bits/stdc++.h>

using ll = long long;
using namespace std;
ll n,k;
ll dp[200][200000];
pair<ll,ll> cost[200][2];
ll mmx;
int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            cin >> cost[i][j].first >> cost[i][j].second;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j] = -999999999;
        }
    }
    dp[1][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int l=0;l<2;l++){
                dp[i+1][j+cost[i][l].first] = max(dp[i+1][j+cost[i][l].first],dp[i][j] + cost[i][l].second);
            }
        }
    }
    for(int j=0;j<=k;j++){
        mmx = max(mmx,dp[n+1][j]);
    }
    cout << mmx;
}