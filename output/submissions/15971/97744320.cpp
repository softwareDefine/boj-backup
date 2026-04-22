#include <bits/stdc++.h>

using namespace std;

int n,s,e;
vector<pair<int,int>> edge[200000];
bool visited[200000];

void go(int now,int mmx,int sum){
    if(now == e){
        cout << sum - mmx;
        return;
    }
    for(auto [next,cost] : edge[now]){
        if(!visited[next]){
            visited[next] = 1;
            go(next,max(mmx,cost),sum+cost);
        }
    }
}

int main(){
    cin >> n >> s >> e;
    for(int i=0;i<n-1;i++){
        int u,v,c;
        cin >> u >> v >> c;
        edge[u].push_back({v,c});
        edge[v].push_back({u,c});
    }
    visited[s] = 1;
    go(s,0,0);
}