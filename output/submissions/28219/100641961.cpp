#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n, k;

lint dp[400000];

vector<lint> edge[400000];

lint ans, mmn = 999999;

lint dfs(int now,int before){
    lint mmx1 = 0, mmx2 = 0;
    for(auto &next : edge[now]){
        if(next == before){continue;}
        lint child = dfs(next, now);
        if(mmx1 <= child+1){
            mmx2 = mmx1;
            mmx1 = child+1;
        }
    }
    if(mmx1 + mmx2 >= k){
        ans++;
        //cout << now << ' ' <<mmx1 << ' ' << mmx2  << '\n';
        return dp[now] = 0;
    }else{
        return dp[now] = mmx1;
    }
}

int main(){
    cin >> n >> k;
    for(int i=0;i<n-1;i++){
        lint u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        ans = 0;
        fill(dp,dp+n+1,0);
        dfs(i,-1);
        mmn = min(mmn, ans);
    }
    cout << mmn;
}