#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int n;
ll dp[300000][2][2];
ll arr[300000];

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    for(int i=1;i<=n;i++){
        if(i == n){
            dp[n][0][0] = max(dp[n-1][0][0],dp[n-1][1][0]) + arr[n];
            dp[n][1][0] = dp[n-1][0][0]+1;
            dp[i][0][1] = max(dp[i-1][0][1],dp[i-1][1][1])+ arr[i];
            cout << max(max(dp[n][0][0],dp[n][1][0]),dp[n][0][1]);
        }
        if(i == 1){
            dp[i][0][0] = arr[i];
            dp[i][1][1] = 1;
        }else{
            dp[i][0][1] = max(dp[i-1][0][1],dp[i-1][1][1])+ arr[i];
            dp[i][1][1] = dp[i-1][0][1] + 1;
            dp[i][0][0] = max(dp[i-1][0][0],dp[i-1][1][0])+ arr[i];
            dp[i][1][0] = dp[i-1][0][0] + 1;
        }
    }
}