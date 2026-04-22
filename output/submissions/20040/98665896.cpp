#include <bits/stdc++.h>

using namespace std;
int n,m;
int q;
int parent[600000];

int find(int now){
    if(parent[now] == now){
        return now;
    }
    return parent[now] = find(parent[now]);
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    iota(parent,parent+600000,0);
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        if(find(u) == find(v)){
            cout << i;
            return 0;
        }
        parent[find(u)] = find(v);
    }
    cout << 0;
    return 0;
}