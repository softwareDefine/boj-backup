#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int cost[20000];
int before[20000];
vector<pair<int,int>> vc[20000]; // now cost
int s,e;

priority_queue<pair<int,int>> pq; // -cost now

void solve(int start,int end){
    cost[start] = 0;
    pq.push({0,start});
    while(!pq.empty()){
        int now = pq.top().second;
        int nowc = -pq.top().first;
        pq.pop();
        if(cost[now] < nowc){ continue; }
        for(auto &j : vc[now]){
            if(cost[j.first] > nowc + j.second){
                cost[j.first] = nowc+ j.second;
                before[j.first] = now;
                pq.push({-cost[j.first],j.first});
            }
        }
    }
    vector<int> city;
    cout << cost[end] << '\n';
    int point = end;
    while(point != start){
        city.push_back(point);
        point = before[point];
    }
    city.push_back(start);
    cout << city.size() << '\n';
    for(int i=city.size()-1; i>=0;i--){
        cout << city[i] << ' ';
    }
}

int main(){
    cin >> n;
    cin >> m;
    for(int i=1;i<=n;i++){ cost[i] = 9999999;}
    for(int i=0;i<m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        vc[u].push_back({v,c});
    }
    cin >> s >> e;
    solve(s,e);
    
}