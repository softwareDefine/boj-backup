#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> edge[200];
int in[200];
int out[200];
int visited[200];

int go1(int now){
    int sum = 0;
    for(auto next : edge[now]){
        if(!visited[next]){
            visited[next] = 1;
            in[next]++;
            sum++;
            sum += go1(next);
        }
    }
    return sum;
}

int main(){
    cin >> n;
    cin >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        memset(visited,0,sizeof(visited));
        out[i] = go1(i);
    }
    for(int i=1;i<=n;i++){
        cout << n-out[i]-in[i]-1 << '\n';
    }
}