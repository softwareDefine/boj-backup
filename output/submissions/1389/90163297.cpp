#define fastio cin.tie(0)->sync_with_stdio(false)
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m;
vector<int> edge[110]; 
queue<pair<int,int>> qu;
pair<int,int> mmn = {999999,0};
int cost[110];

int bfs(int now){
    qu.push({now,0});
    cost[now] = 0;
    while(!qu.empty()){
        int now = qu.front().first;
        int ctemp = qu.front().second;
        qu.pop();
        for(auto &next : edge[now]){
            if(cost[next] > ctemp+1){
                cost[next] = ctemp+1;
                qu.push({next,ctemp+1});
            }
        }
    }
    int ac = 0;
    for(int i=1;i<=n;i++){
        ac+=cost[i];
    }
    return ac;
}

int main(){
    fastio;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x ,y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        fill_n(cost,110,999999);
        int a = bfs(i);
        if(a < mmn.first){
            mmn = {a,i};
        }
    }
    cout << mmn.second;
}