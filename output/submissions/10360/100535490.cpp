#define inf 1000000009
#include <bits/stdc++.h>

using lint = long long;
using namespace std;

vector<pair<lint, lint>> edge[2000];
lint t;
int cnter;
lint dist[2000];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while(t--){
        lint n, m;
        int flag = 0;
        cnter++;
        fill(dist, dist+2000, inf);
        dist[0] = 0;
        for(int i = 0; i<2000;i++){
            edge[i].clear();
        }
        cin >> n >> m;
        for(int i = 0; i<m;i++){
            lint u, v, c;
            cin >> u >> v >> c;
            edge[u].push_back({v,c});
        }
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n; j++){
                for(auto [next, cost] : edge[j]){
                    if(dist[j] != inf && dist[next] > dist[j] + cost){
                        dist[next] = dist[j] + cost;
                        if(i == n-1){
                            flag = 1;
                        }
                    }
                }
            }
        }
        cout << "Case #" << cnter << ": ";
        if(!flag){
            cout << "not ";
        }
        cout << "possible\n";
    }
}