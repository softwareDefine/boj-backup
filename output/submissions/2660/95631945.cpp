#include <bits/stdc++.h>

using namespace std;

int n;
int mmx[10010];
vector<int> vc[10010];
int visited[10010];
int mmn = 999;
vector<int> candidate;

int bfs(int start){
    queue<pair<int,int>> qu;
    qu.push({start,0});
    visited[start] = 0;
    while(!qu.empty()){
        int now = qu.front().first;
        int cnt = qu.front().second;
        qu.pop();
        for(auto &nx : vc[now]){
            if(visited[nx] == -1){
                visited[nx] = cnt+1;
                qu.push({nx,cnt+1});
            }
        }
    }
    for(int i=1;i<=n;i++){
        mmx[start] = max(mmx[start], visited[i]);
    }
    return mmx[start];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while(1){
        int u,v;
        cin >> u >> v;
        if( u == -1 && v == -1){
            break;
        }
        vc[u].push_back(v);
        vc[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        fill_n(visited,100,-1);
        mmn = min(mmn,bfs(i));
    }
    for(int i=1;i<=n;i++){
       if(mmn == mmx[i]){
            candidate.push_back(i);
       }
    }
    cout << mmn << " " << candidate.size() << '\n';
    for(auto &x : candidate){
        cout << x << " ";
    }
}