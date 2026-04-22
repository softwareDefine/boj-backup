#include <bits/stdc++.h>

using namespace std;
int n;

int dp[600][600];
pair<int,int> arr[600];

int go(int start,int end){
    if(dp[start][end] != 999999999){return dp[start][end];}
    for(int i=start+1;i<=end;i++){
        dp[start][end] = min(dp[start][end],go(start,i-1) + go(i,end) + arr[start].first * arr[i-1].second * arr[end].second);
    }
    return dp[start][end];
}

int main(){
    for(int i=0;i<550;i++){
        for(int j=0;j<550;j++){
            if(i==j){
                continue;
            }
            dp[i][j] = 999999999;
        }
    }
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    cout << go(0,n-1);
}