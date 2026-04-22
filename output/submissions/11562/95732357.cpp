#include<bits/stdc++.h>

using namespace std;

int dist[400][400];
int n,m,k;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<400;i++){
        for(int j=0;j<400;j++){
            if(i==j){
                dist[i][j] = 0;
                continue;
            }
            dist[i][j] = 99999;
        }
    }
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,b;
        cin >> u >> v >> b;
        if(b == 0){
            dist[u][v] = 1;
            dist[v][u] = 250;
        }else{
            dist[u][v] = 1;
            dist[v][u] = 1;
        }
    }
    for(int k2=1;k2<=n;k2++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k2]+dist[k2][j]);
            }
        }
    }
    cin >> k;
    for(int i=0;i<k;i++){
        int s,e;
        cin >> s >> e;
        if(dist[s][e] <= 249){
            cout << 0 << '\n';
        }else{
            cout << dist[s][e]/250 << '\n';
        }
    }
}