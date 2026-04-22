#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> bus[1100];
int cost[1100];
int s,e;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int bfs(){
    cost[s] = 0;
    pq.push({0,s});
    while(!pq.empty()){
        int now = pq.top().second;
        int nowcost = pq.top().first;
        for(auto &i : bus[now]){
            if(i.first + nowcost < bus[i.second]){
                bus[i.second] = i.first + nowcost;
                pq.push_back({bus[i.second],i.second});
            }
        }
        pq.pop();
    }
    return bus[e];
}

int main(){
    cin >> n;
    cin >> m;
    for(int i=0;i<m;i++){
        int x,y,c;
        cin >> x >> y >> c;
        bus[x].push_back({c,y});
    }
    cin >> s >> e;
    cout << bfs();
}