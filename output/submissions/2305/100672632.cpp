#include <bits/stdc++.h>

using namespace std;
int n, k;

int dp[200][2];
int ans;

int main()
{
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 0;
    dp[2][0] = 1;
    dp[2][1] = 1;
    for(int i=3;i<=40;i++){
        dp[i][1] = dp[i-2][0] + dp[i-2][1];
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
    }
    cin >> n >> k;
    ans += (dp[n-k][0] + dp[n-k][1])*(dp[k-1][0]+dp[k-1][1]);
    for(int i=1;i<=n;i++){
        if( i == k ){ continue; }
        else if( i < k){
            int tmp = 0;
            for(int j = 1; j < k; j++){
                if( i <= j){
                    tmp += (dp[i-1][0] + dp[i-1][1])*(dp[k-1-j][0] + dp[k-1-j][1]);
                }else{
                    tmp += (dp[j-1][0] + dp[j-1][1])*(dp[k-1-i][0] + dp[k-1-i][1]);
                }
            }
            tmp *= (dp[n-k][0]+dp[n-k][1]);
            ans += tmp;
        }else if( i > k ){
            int tmp = 0;
            for(int j = k+1; j <= n; j++){
                if( i <= j){
                    tmp += (dp[k+1-i][0] + dp[k+1-i][1])*(dp[n-j][0] + dp[n-j][1]);
                }else{
                    tmp += (dp[k+1-j][0] + dp[k+1-j][1])*(dp[n-i][0] + dp[n-i][1]);
                }
            }
            tmp *= (dp[k-1][0]+dp[k-1][1]);
            ans += tmp;
        }
    }
    cout << ans;
    return 0;
}