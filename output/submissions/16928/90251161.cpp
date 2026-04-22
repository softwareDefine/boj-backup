#define fastio cin.tie(0)->sync_with_stdio(0)
#include <bits/stdc++.h>

using namespace std;

int cost[110];
int door[110];

int n,m;

int bfs(){
    queue<pair<int,int>> qu;
    qu.push({1,0});
    while(!qu.empty()){
        int now = qu.front().first;
        int nowc = qu.front().second;
        qu.pop();
        if(door[now]){
            qu.push({door[now],nowc});
            cost[door[now]] = nowc;
        }else{
            for(int i=1;i<=6;i++){
                if(now+i < 101 && cost[now+i] > nowc+1){
                    qu.push({now+i,nowc+1});
                    cost[now+i] = nowc+1;
                }
            }
        }
    }
    return cost[100];
}

int main(){
    fill_n(cost,101,99999);
    cost[1] = 0;
    cin >> n >> m;
    for(int i=0;i<n+m;i++){
        int u,v;
        cin >> u >> v;
        door[u] = v;
    }
    cout << bfs();
}