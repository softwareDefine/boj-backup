#define fastio cin.tie(0)->sync_with_stdio(0)
#include<bits/stdc++.h>

using namespace std;

int n,m;
int mp[2000][2000];
int cost[2000][2000];
queue<pair<pair<int,int>,int>> qu;
pair<int,int> ed;

void bfs(){
    qu.push({ed,0});
    while (!qu.empty())
    {
        pair<int,int> now = qu.front().first;
        int nowcost = qu.front().second;
        qu.pop();
        if(now.first + 1 < n && mp[now.first+1][now.second] != 0 && cost[now.first+1][now.second] > nowcost +1){
            qu.push({{now.first+1,now.second},nowcost+1});
            cost[now.first +1][now.second] = nowcost + 1;
        }
        if(now.first - 1 > -1 && mp[now.first-1][now.second] != 0 && cost[now.first-1][now.second] > nowcost +1){
            qu.push({{now.first-1,now.second},nowcost+1});
            cost[now.first -1][now.second] = nowcost + 1;
        }
        if(now.second + 1 < m && mp[now.first][now.second+1] != 0 && cost[now.first][now.second+1] > nowcost +1){
            qu.push({{now.first,now.second+1},nowcost+1});
            cost[now.first ][now.second+1] = nowcost + 1;
        }
        if(now.second - 1 > -1 && mp[now.first][now.second-1] != 0 && cost[now.first][now.second-1] > nowcost +1){
            qu.push({{now.first,now.second-1},nowcost+1});
            cost[now.first +1][now.second-1] = nowcost + 1;
        }
    }
}

int main(){
    fastio;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cost[i][j] = 9999999;
            cin >> mp[i][j];
            if(mp[i][j] == 2){
                ed.first = i;
                ed.second = j;
                cost[i][j] = 0;
            }
            if(!mp[i][j]) cost[i][j] = 0;
        }
    }
    bfs();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(cost[i][j] == 9999999){
                cout << -1 << ' ';
            }else{
                cout << cost[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}