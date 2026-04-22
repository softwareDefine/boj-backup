#define inf 100000000009
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
        int before = 0, after = 0;
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
        for(int i = 0; i < 2*n;i++){
            for(int j = 0; j < n; j++){
                for(auto [next, cost] : edge[j]){
                    if(dist[j] != inf && dist[next] > dist[j] + cost){
                        dist[next] = dist[j] + cost;
                        if(i == n-2){
                            before = dist[0];
                        }else if(i == 2*n-1){
                            after = dist[0];
                        }
                    }
                }
            }
        }
        cout << "Case #" << cnter << ": ";
        if(after >= before){
            cout << "not ";
        }
        cout << "possible\n";
    }
}