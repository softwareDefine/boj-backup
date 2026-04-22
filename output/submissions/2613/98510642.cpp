#include <bits/stdc++.h>

using namespace std;

int n,m;

int sum[400];
int arr[400];
int dp[400][200];
pair<int,int> before[400][200];
void go(int i,int j){
    if(!j){return;}
    go(before[i][j].first,before[i][j].second);
    cout << i - before[i][j].first << ' ';
}

int main(){
    cin >> n >> m;
    for(int i=0;i<400;i++){
        for(int j=0;j<200;j++){
            dp[i][j] = 999999999;
        }
    }
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1] + arr[i];
    }
    dp[0][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=0;k<=n;k++){
                if(dp[j][k+1] > max(dp[i][k],sum[j] - sum[i])){
                    before[j][k+1] = {i,k};
                    dp[j][k+1] = min(dp[j][k+1], max(dp[i][k],sum[j] - sum[i]));
                }
            }
        }
    }
    cout << dp[n][m] << '\n';
    go(n,m);
}