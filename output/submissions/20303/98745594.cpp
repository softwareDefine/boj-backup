#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n,m,k;

lint arr[40000];
int parent[40000];
pair<lint,lint> total[40000];
vector<pair<lint,lint>> vc;
lint dp[40000][5000];
lint mmx;

int find(int now){
    if(parent[now] == now){
        return now;
    }
    return parent[now] = find(parent[now]);
}

int main(){
    iota(parent,parent+40000,0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    while(m--){
        lint a,b;
        cin >> a >> b;
        if(b < a){swap(a,b);}
        parent[find(b)] = find(a);
    }
    for(int i=1;i<=n;i++){
        total[find(i)].second++;
        total[find(i)].first += arr[i];
    }
    for(int i=1;i<=n;i++){
        if(total[i].second){
            vc.push_back(total[i]);
        }
    }
    for(int i=0;i<vc.size();i++){
        for(int j=0;j<=3000;j++){
            lint before =0;
            if(i-1>=0){
                before = dp[i-1][j];
            }
            dp[i][j] = max(dp[i][j],before);
            dp[i][j+vc[i].second] = max(dp[i][j+vc[i].second], before + vc[i].first);
        }
    }
    // for(int i=0;i<vc.size();i++){
    //     for(int j=0;j<=k-1;j++){
    //         cout << dp[i][j] << ' ';
    //         mmx = max(mmx,dp[i][j]);
    //     }
    //     cout << '\n';
    // }
    cout << dp[vc.size()-1][k-1];
}