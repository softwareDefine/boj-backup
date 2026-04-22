#include <bits/stdc++.h>

using namespace std;

int n,m;
bool isAct[110000];
long long cost[110000];
vector<pair<int,int>> vc[110000]; // next cost

long long solve(){
    priority_queue<pair<long long,int>> pq; // cost next
    cost[0] = 0;
    pq.push({-0,0});
    while(!pq.empty()){
        int now = pq.top().second;
        long long nowc = -pq.top().first;
        pq.pop();
        cout << now << '\n';
        if(cost[now] < nowc){ continue; }
        for(auto &next : vc[now]){
            if(cost[next.first] > next.second + cost[now]){
                cost[next.first] = next.second + cost[now];
                pq.push({-cost[next.first],next.first});
            }
        }
    }
    return cost[n-1];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> isAct[i];
        cost[i] =  9999999999LL;
    }
    isAct[n-1] = 0;
    for(int i=0;i<m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        if(!isAct[u] && !isAct[v]){
            vc[u].push_back({v,c});
            vc[v].push_back({u,c});
        }
    }
    long long ans = solve();
    cout << (ans == 9999999999LL) ? ans : -1;
}