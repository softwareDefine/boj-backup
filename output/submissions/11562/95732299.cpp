#include<bits/stdc++.h>

using namespace std;

int dist[400][400];

int abledist[400][400];
int visited[400];
vector<int> vc[400];

int n,m,k;

int bfs(int start){
    visited[start] = 1;
    queue<pair<int,int>> qu;
    qu.push({start,0});
    abledist[start][start] = 0;
    while(!qu.empty()){
        int now = qu.front().first;
        int cnt = qu.front().second;
        qu.pop();
        for(auto &nx : vc[now]){
            if(!visited[nx]){
                qu.push({nx,cnt+1});
                abledist[start][nx] = cnt+1;
                visited[nx] = 1;
            }
        }
    }
}

int main(){
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
        vc[u].push_back(v);
        vc[v].push_back(u);
        if(b == 0){
            dist[u][v] = 1;
            dist[v][u] = 2;
        }else{
            dist[u][v] = 1;
            dist[v][u] = 1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            visited[j] = 0;
        }
        bfs(i);
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
        cout << dist[s][e]-abledist[s][e] << '\n';
    }
}