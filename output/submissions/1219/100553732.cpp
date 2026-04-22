#define inf 1000000009
#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n, m, s, e;
vector<pair<lint,lint>> edge[100];
lint earn[100];
lint dist[100];
lint before, after = inf;

int main(){
    cin >> n >> s >> e >> m;
    fill(dist, dist+100, inf);
    for(int i = 0; i < m; i++){
        lint u, v, c;
        cin >> u >> v >> c;
        edge[u].push_back({v,c});
    }
    for(int i=0; i < n; i++){
        cin >> earn[i];
    }
    dist[s] = -earn[s];
    for(int i=0;i<2*n;i++){
        for(int j=0;j<n;j++){
            for(auto &[v, c] : edge[j]){
                if(dist[j] != inf && dist[v] > dist[j] + c - earn[v]){
                    dist[v] = dist[j] + c - earn[v];
                    if(i == n-2){
                        before = dist[e];
                    }else if(i == n-1){
                        c = -inf;
                    }else if(i == 2*n-1){
                        after = dist[e];
                    }
                }
            }
        }
    }
    if(before > after){
        cout << "Gee";
        return 0;
    }
    if(dist[e] == inf){
        cout << "gg";
        return 0;
    }else{
        cout << -dist[e];
    }
}