#define fastio cin.tie(0)->sync_with_stdio(0)
#include <bits/stdc++.h>

using namespace std;

int t;
int sticker[3][110000];
int dp[3][110000][2];

int main(){
    cin >> t;
    while(t--){
        for(int i=0;i<2;i++){
            for(int j=0;j<110000;j++){
                for(int k=0;k<2;k++){
                    dp[i][j][k] = 0;
                }
            }
        }
        int n;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> sticker[1][i];
        }
        for(int i=1;i<=n;i++){
            cin >> sticker[2][i];
        }
        for(int i=1;i<=n;i++){
            dp[1][i][1] = max(dp[2][i-1][1],max(dp[2][i-1][0],dp[1][i-1][0])) + sticker[1][i];
            dp[2][i][1] = max(dp[1][i-1][1],max(dp[1][i-1][0],dp[2][i-1][0])) + sticker[2][i];
            dp[1][i][0] = max(dp[1][i-1][1],max(dp[1][i-1][0],max(dp[2][i-1][1],dp[2][i-1][0])));
            dp[2][i][0] = max(dp[2][i-1][1],max(dp[2][i-1][0],max(dp[1][i-1][1],dp[1][i-1][0])));
        }
        cout << max(dp[1][n][1],max(dp[2][n][1],max(dp[1][n][0],dp[2][n][0]))) << '\n';
    }
    
}