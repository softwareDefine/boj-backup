#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;

vector<int> edge[300010];

vector<int> path;

lint dtree[300010];
lint gtree[300010];

lint smD;
lint smG;

lint visited[300010];

void go(int now){
    visited[now] = 1;
    if(edge[now].size() >= 3){
        gtree[now] += edge[now].size() * (edge[now].size() - 1) * (edge[now].size() - 2) / 6; 
    }
    for(auto next : edge[now]){
        dtree[now] += (edge[next].size()-1)*(edge[now].size()-1);
        if(!visited[next]){
            go(next);
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    go(1);
    for(int i = 1; i <= n;i++){
        smG += gtree[i];
        smD += dtree[i];
    }
    smD/=2;
    if(smD > smG*3){
        cout << 'D';
    }else if(smD < smG*3){
        cout << 'G';
    }else{
        cout << "DUDUDUNGA";
    }
	return 0;
}