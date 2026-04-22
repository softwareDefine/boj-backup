#include <bits/stdc++.h>

using namespace std;

int n,k;
int s;
int dist[500][500];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<500;i++){
        for(int j=0;j<500;j++){
            if(i==j){
                dist[i][j] = 0;
                continue;
            }
            dist[i][j] = 99999;
        }
    }
    cin >> n >> k;
    for(int i=0;i<k;i++){
        int u,v;
        cin >> u >> v;
        dist[u][v] = 1;
    }
    for(int k2=1;k2<=n;k2++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j] > dist[i][k2] + dist[k2][j]){
                    dist[i][j] = dist[i][k2] + dist[k2][j];
                }
            }
        }
    }
    cin >> s;
    for(int i=0;i<s;i++){
        int u,v;
        cin >> u >> v;
        if(dist[u][v] != 99999){
            cout << -1 << '\n';
        }else if(dist[v][u] != 99999){
            cout << 1 << '\n';
        }else{
            cout << 0 << '\n';
        }
    }
}