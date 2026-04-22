#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int n,m;
ll dp[100][400];
int arr[100][400];
ll mmx;
pair<int,int> mmxidx;
vector<int> vc;

void go(int company,int cost){
    if(company == 0){
        return;
    }
    for(int j=cost;j>=0;j--){
        if(dp[company][cost] == dp[company-1][cost-j]+arr[company][j]){
            go(company-1,cost-j);
            vc.push_back(j);
            return;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int c;
        cin >> c;
        for(int j=1;j<=m;j++){
            cin >> arr[j][c];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = dp[i-1][j];
            for(int k=0;k<=j;k++){
                dp[i][j] = max(dp[i][j],dp[i-1][j-k] +arr[i][k]);
                if(mmx < dp[i][j]){
                    mmx = dp[i][j];
                    mmxidx = {i,j};
                }
            }
        }
    }
    go(mmxidx.first,mmxidx.second);
    cout << mmx << '\n';
    for(auto i : vc){
        cout << i << ' ';
    }
}