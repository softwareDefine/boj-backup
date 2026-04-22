#define fastio cin.tie(0)->sync_with_stdio(0)
#include <bits/stdc++.h>

using namespace std;

int t;
int parent[11000000];

int find(int now){
    if(parent[now] == now){
        return now;
    }
    return parent[now] = find(parent[now]);
}


int main(){
    fastio;
    cin >> t;
    for(int i=1;i<=t;i++){
        int n;
        cin >> n;
        for(int p=0;p<=n;p++){
            parent[p] = p;
        }
        int k;
        cin >> k;
        for(int j=0;j<k;j++){
            int u,v;
            cin >> u >> v;
            if(find(u) != find(v)){
                parent[u] = v;
            }
        }
        int m;
        cin >> m;
        cout << "Scenario " << i <<":" << '\n'; 
        for(int j=0;j<m;j++){
            int u,v;
            cin >> u >> v;
            if(find(u) != find(v)){
                cout << 0 << '\n';
            }else{
                cout << 1 << '\n';
            }
        }
        cout << '\n';
    }
}