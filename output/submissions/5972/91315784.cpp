#include <bits/stdc++.h>

using namespace std;

int n,r;
vector<pair<int,int>> vc[510000];
priority_queue<pair<long long,int>> pq; // cost , nextcoor
long long cost[510000];

int solve(int start,int end){
    cost[start] = 0;
    pq.push({0,start});
    while(!pq.empty()){
        int now = pq.top().second;
        int nowcost = -pq.top().first;
        pq.pop();
        if(cost[now] < nowcost){ continue; }
        for(auto &next : vc[now]){
            if(cost[next.first] > nowcost + next.second){
                cost[next.first] = nowcost + next.second;
                pq.push({-cost[next.first],next.first});
            }
        }
    }
    return cost[end];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> r;
    for(int i=0;i<r;i++){
        int u,v,c;
        cin >> u >> v >> c;
        vc[u].push_back({v,c});
        vc[v].push_back({u,c});
    }
    cout << solve(1,n);
}