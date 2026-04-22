#include <bits/stdc++.h>

using namespace std;

int n,m;
int s,e;
int visited[10010];
vector<int> vc[10010];

void dfs(int start,int cnt){
    for(auto i : vc[start]){
        if(visited[i] > cnt+1){
            visited[i]=cnt+1;
            dfs(i,cnt+1);
        }
    }
}

int main(){
    for(int i=0;i<10010;i++){
        visited[i]= 99999;
    }
    cin >> n;
    cin >> s >> e;
    cin >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        vc[u].push_back(v);
        vc[v].push_back(u);
    }
    visited[s] =0;
    dfs(s,0);
    cout << ((visited[e] != 99999) ? visited[e] : -1);
}