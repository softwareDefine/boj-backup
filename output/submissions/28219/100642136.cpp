#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n, k;

lint dp[400000];

vector<lint> edge[400000];

lint ans;

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
        return dp[now] = -1;
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
    dfs(1,-1);
    cout << ans;
}