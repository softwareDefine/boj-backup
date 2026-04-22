#include<bits/stdc++.h>

using namespace std;

vector<pair<long long,long long>> bus[1100];
long long cost[1100];
int s,e,n,m;

priority_queue<pair<long long,long long>> pq;

int bfs(){
    cost[s] = 0;
    pq.push({0,s});
    while(!pq.empty()){
        int now = pq.top().second;
        long long nowcost = -pq.top().first;
        pq.pop();
        for(int i=0;i<bus[now].size();i++){
            if(bus[now][i].first + nowcost < cost[bus[now][i].second]){
                cost[bus[now][i].second] = bus[now][i].first + nowcost;
                pq.push({-cost[bus[now][i].second],bus[now][i].second});
            }
        }
    }
    return cost[e];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int i=0;i<1100;i++){
        cost[i] = 999999999;
    }
    cin >> n;
    cin >> m;
    for(int i=0;i<m;i++){
        int x,y,c;
        cin >> x >> y >> c;
        bus[x].push_back({c,y});
        bus[y].push_back({c,x});
    }
    cin >> s >> e;
    cout << bfs();
}