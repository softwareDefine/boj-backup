#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> edge[200000];
int in[200000];
int start[200000];
int chk[200000];
int mac;

queue<int> qu;

int main(){
    cin >> n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        edge[u].push_back(v);
        in[v]++;
    }
    for(int i=1;i<=n;i++){
        if(!(in[i])){
            qu.push(i);
            chk[i] = 1;
            start[i] = 1; 
            mac++;
        }
    }
    while(!qu.empty()){
        int now = qu.front();
        qu.pop();
        if(edge[now].size() >= 2){ continue; }
        for(auto next : edge[now]){
            chk[next] += chk[now];
            in[next]--;
            if(in[next] == 0){
                qu.push(next);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!start[i] && chk[i] == mac){
            cout << i << '\n';
        }
    }
}