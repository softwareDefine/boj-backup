#include <bits/stdc++.h>

using namespace std;
int n,m;
int cost[1000];
vector<pair<int,int>> vc[1000];
priority_queue<pair<int,pair<int,int>>> pq; // cost , < next, 경유>
int inter[1000][1000];

void solve(int start){
    cost[start] = 0;
    pq.push({0,{start,0}});
    while(!pq.empty()){
        int now = pq.top().second.first;
        int intern = pq.top().second.second;
        int nowcost = -pq.top().first;
        pq.pop();
        if(cost[now] < nowcost){continue;}
        for(auto &i : vc[now]){
            int nx = i.first;
            int nxc = i.second;
            if(cost[nx] > nowcost + nxc){
                cost[nx] = nowcost + nxc;
                if(intern == 0){
                    inter[start][nx] = nx;  
                    pq.push({-cost[nx],{nx,nx}});
                    continue;
                }
                inter[start][nx] = intern; 
                pq.push({-cost[nx],{nx,intern}});
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        vc[u].push_back({v,c});
        vc[v].push_back({u,c});
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){ cost[j] = 99999999; }
        solve(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(inter[i][j] == 0){
                cout << "- ";
                continue;
            }
            cout << inter[i][j] << ' ';
        }
        cout << '\n';
    }
}