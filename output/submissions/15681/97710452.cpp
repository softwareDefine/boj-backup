#include <bits/stdc++.h>

using namespace std;

int n,r,q;

int child[200000];
vector<int> edge[200000];

int go(int now){
    child[now] += 1;
    for(auto element : edge[now]){
        if(!child[element]){
            child[now] += go(element);
        }
    }
    return child[now];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> r >> q;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    go(r);
    for(int i=0;i<q;i++){
        int u;
        cin >> u;
        cout << child[u] << '\n';
    }
}