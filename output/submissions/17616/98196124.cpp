#include <bits/stdc++.h>

using namespace std;

int n,m,x;
vector<int> reverser[200000];
vector<int> correct[200000];
int visited[200000];
int best,worst;

void go(int now){
    for(auto next : correct[now]){
        if(!visited[next]){
            visited[next] = 1;
            go(next);
        }
    }
}

void backword(int now){
    for(auto next : reverser[now]){
        if(!visited[next]){
            visited[next] = 1;
            backword(next);
        }
    }
}

int main(){
    cin >> n >> m >> x;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        reverser[v].push_back(u);
        correct[u].push_back(v);
    }
    visited[x] = 1;
    go(x);
    for(int i=1;i<=n;i++){ if(visited[i]){worst++;}}
    memset(visited,0,sizeof(visited));
    visited[x] = 1;
    backword(x);
    for(int i=1;i<=n;i++){ if(visited[i]){best++;}}
    cout << best << ' ' <<n-worst+1;
}