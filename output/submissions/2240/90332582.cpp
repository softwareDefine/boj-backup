#define fastio cin.tie(0)->sync_with_stdio(0)
#include <bits/stdc++.h>

using namespace std;


int t,w;
int dp[1100][3][40];
int flow[1100];

int main(){
    cin >> t >> w;
    for(int i=1;i<=t;i++){
        cin >> flow[i];
    }
    for(int i=1;i<=t;i++){
        if(i == 1 && flow[i] == 1)
        {
            dp[1][1][0] = 1;
            continue;
        }
        for(int j=0;j<=min(i-1,w);j++){
            if(flow[i] == 1){
                if(j == 0){
                    dp[i][1][j] = dp[i-1][1][j] +1;
                    dp[i][2][j] = dp[i-1][2][j];
                    continue;
                }
                dp[i][1][j] = max(dp[i-1][2][j-1],dp[i-1][1][j]) +1;
                dp[i][2][j] = max(dp[i-1][1][j-1],dp[i-1][2][j]);
            }else{
                if(j == 0){
                    dp[i][1][j] = dp[i-1][1][j];
                    dp[i][2][j] = dp[i-1][2][j]+1;
                    continue;
                }
                dp[i][1][j] = max(dp[i-1][2][j-1],dp[i-1][1][j]);
                dp[i][2][j] = max(dp[i-1][1][j-1],dp[i-1][2][j])+1;
            }
        }
    }
    cout << max(dp[t][1][w],dp[t][2][w]);
}