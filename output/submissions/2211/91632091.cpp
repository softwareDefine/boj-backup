#include <bits/stdc++.h>

using namespace std;
int n,m;
int cost[5000];
pair<int,int> who[5000];
vector<pair<int,int>> vc[5000]; // next cost

void solve(){
    priority_queue<pair<int,int>> pq; // cost next
    cost[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        int now = pq.top().second;
        int nowc = -pq.top().first;
        pq.pop();
        if(cost[now] < nowc){ continue; }
        for(auto &j : vc[now]){
            if(cost[j.first] > nowc + j.second ){
                cost[j.first] = nowc + j.second;
                who[j.first] = {now,j.first};
                pq.push({-cost[j.first],j.first});
            }
        }
    }
}

int main(){
    for(int i=0;i<5000;i++){ cost[i] = 99999; }
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        vc[u].push_back({v,c});
        vc[v].push_back({u,c});
    }
    solve();
    cout << n-1 << '\n';
    for(int i=2;i<=n;i++){
        cout << who[i].first << ' ' << who[i].second << '\n'; 
    }
}