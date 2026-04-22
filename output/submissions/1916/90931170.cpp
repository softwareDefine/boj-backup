#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> bus[1100];
int cost[1100];
int s,e,n,m;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int bfs(){
    cost[s] = 0;
    pq.push({0,s});
    while(!pq.empty()){
        int now = pq.top().second;
        int nowcost = pq.top().first;
        for(auto &i : bus[now]){
            if(i.first + nowcost < cost[i.second]){
                cost[i.second] = i.first + nowcost;
                pq.push({cost[i.second],i.second});
            }
        }
        pq.pop();
    }
    return cost[e];
}

int main(){ios::sync_with_stdio(false)
cin.tie(nullptr)
cout.tie(nullptr)
    for(int i=0;i<1100;i++){
        cost[i] = 9999999;
    }
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