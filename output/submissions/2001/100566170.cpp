#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n, m, k;

typedef struct{
    lint now;
    lint jewerly;
    lint cnt;
}Node;

lint visited[200][60000];
lint jewMap[200];
lint idx2map[200];
lint ans;
queue<Node> qu;
vector<pair<lint,lint>> edge[200];
int main(){
    fill(idx2map,idx2map+200,15);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        int idx;
        cin >> idx;
        idx2map[idx-1] = i;
        jewMap[idx-1] = 1;
    }
    for(int i = 0; i < m; i++){
        lint u, v, c;
        cin >> u >> v >> c;
        edge[u-1].push_back({v-1, c});
        edge[v-1].push_back({u-1, c});
    }
    qu.push({0,0,0});
    visited[0][0] = 1;
    while(!qu.empty()){
        auto [now, jewerly, cnt] = qu.front();
        if(now == 0){ ans = max(ans, cnt); }
        qu.pop();
        for(auto [next, weight] : edge[now]){
            if((!visited[next][(jewerly|((jewMap[next])<<idx2map[next]))]) && weight >= cnt){
                int get = 0;
                if(!(jewerly&(jewMap[next]<<idx2map[next])) && jewMap[next]){
                    get = 1;
                }
                qu.push({next, (jewerly|((jewMap[next])<<idx2map[next])), cnt+jewMap[next] });
                visited[next][(jewerly|((jewMap[next])<<idx2map[next]))] = 1;
            }
            if((!visited[next][jewerly]) && weight >= cnt){
                qu.push({next, jewerly, cnt });
                visited[next][jewerly] = 1;
            }
        }
    }
    cout << ans;
    return 0;
}