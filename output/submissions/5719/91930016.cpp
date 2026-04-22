#include <bits/stdc++.h>

using namespace std;

int cost[1010];
vector<pair<int,int>> vc[1010];
set<pair<int,int>> snot;
vector<int> before[1010];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    while(1){
        int n,m;
        int s,e;
        cin >> n >> m;
        if(!n && !m){break; }
        cin >> s >> e;
        for(int i=0;i<1010;i++){ vc[i].clear();}
        snot.clear();
        for(int i=0;i<m;i++){
            int u,v,p;
            cin >> u >> v >> p;
            vc[u].push_back({v,p});
        }
        priority_queue<pair<int,int>> pq; // -cost next
        for(int i=0;i<1010;i++){ cost[i] = 99999999; before[i].clear(); }
        cost[s] = 0;
        pq.push({-0,s});
        while(!pq.empty()){
            int now = pq.top().second;
            int ncost = -pq.top().first;
            pq.pop();
            if(cost[now] < ncost){ continue; }
            for(auto &j : vc[now]){
                if(cost[j.first] > ncost + j.second){
                    cost[j.first] = ncost + j.second;
                    before[j.first].clear();
                    pq.push({-cost[j.first],j.first});
                }
                if(cost[j.first] == ncost + j.second){
                    before[j.first].push_back(now);
                }
            }
        }
        queue<int> qu;
        for(auto &i : before[e]){
            snot.insert({i,e});
            qu.push(i);
        }
        while(!qu.empty()){
            int now = qu.front();
            qu.pop();
            for(auto &i : before[now]){
                snot.insert({i,now});
                qu.push(i);
            }
        }
        for(int i=0;i<1010;i++){ cost[i] = 99999999; }
        cost[s] = 0;
        pq.push({-0,s});
        while(!pq.empty()){
            int now = pq.top().second;
            int ncost = -pq.top().first;
            pq.pop();
            if(cost[now] < ncost){ continue; }
            for(auto &j : vc[now]){
                if(cost[j.first] > ncost + j.second && snot.find({now,j.first}) == snot.end()){
                    cost[j.first] = ncost + j.second;
                    pq.push({-cost[j.first],j.first});
                }
            }
        }
        if(cost[e] == 99999999){
            cout << -1 << '\n';
        }else{
            cout << cost[e] << '\n';
        }
    }
}