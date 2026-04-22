#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;

vector<int> edge[310000];

lint realAns;
lint ans[310000];
lint many[310000];
lint dp[310000];

void dfs(lint now,lint depth,lint parent){
    for(auto next : edge[now]){
        if(next != parent){
            dfs(next, depth+1, now);
            many[now] += many[next];
            dp[now] += dp[next] + many[next];
        }
    }
    many[now] += 1;
    lint later = 0;
    for(auto next : edge[now]){
        if(next != parent){
            ans[now] += (dp[next] + many[next])*(many[now]-many[next]);
            later += depth*(many[now]-many[next]-1)*many[next];
        }
    }
    ans[now] += later/2 + (many[now]-1)*depth;
    realAns += ans[now];
}

int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0, -1);
    cout << realAns;
}