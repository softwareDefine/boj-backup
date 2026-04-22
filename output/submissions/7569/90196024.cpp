#define fastio cin.tie(0)->sync_with_stdio(0)
#include <bits/stdc++.h>

using namespace std;

int m,n,h;
int mmx = 0;
int mp[110][110][110];
int cost[110][110][110];
queue<pair<tuple<int,int,int>,int>> qu;

void bfs(){
    while(!qu.empty()){
        tuple<int,int,int> coor = qu.front().first;
        int nowc = qu.front().second;
        qu.pop();
        if(get<0>(coor) + 1 < h && mp[get<0>(coor)+1][get<1>(coor)][get<2>(coor)] == 0 && cost[get<0>(coor)+1][get<1>(coor)][get<2>(coor)] > nowc+1){
            qu.push({{get<0>(coor)+1,get<1>(coor),get<2>(coor)},nowc+1});
            cost[get<0>(coor)+1][get<1>(coor)][get<2>(coor)] = nowc+1;
        }
        if(get<0>(coor) - 1 > -1 && mp[get<0>(coor)-1][get<1>(coor)][get<2>(coor)] == 0 && cost[get<0>(coor)-1][get<1>(coor)][get<2>(coor)] > nowc+1){
            qu.push({{get<0>(coor)-1,get<1>(coor),get<2>(coor)},nowc+1});
            cost[get<0>(coor)-1][get<1>(coor)][get<2>(coor)] = nowc+1;
        }
        if(get<1>(coor) + 1 < n && mp[get<0>(coor)][get<1>(coor)+1][get<2>(coor)] == 0 && cost[get<0>(coor)][get<1>(coor)+1][get<2>(coor)] > nowc+1){
            qu.push({{get<0>(coor),get<1>(coor)+1,get<2>(coor)},nowc+1});
            cost[get<0>(coor)][get<1>(coor)+1][get<2>(coor)] = nowc+1;
        }
        if(get<1>(coor) - 1 > -1 && mp[get<0>(coor)][get<1>(coor)-1][get<2>(coor)] == 0 && cost[get<0>(coor)][get<1>(coor)-1][get<2>(coor)] > nowc+1){
            qu.push({{get<0>(coor),get<1>(coor)-1,get<2>(coor)},nowc+1});
            cost[get<0>(coor)][get<1>(coor)-1][get<2>(coor)] = nowc+1;
        }
        if(get<2>(coor) + 1 < m && mp[get<0>(coor)][get<1>(coor)][get<2>(coor)+1] == 0 && cost[get<0>(coor)][get<1>(coor)][get<2>(coor)+1] > nowc+1){
            qu.push({{get<0>(coor),get<1>(coor),get<2>(coor)+1},nowc+1});
            cost[get<0>(coor)][get<1>(coor)][get<2>(coor)+1] = nowc+1;
        }
        if(get<2>(coor) - 1 > -1 && mp[get<0>(coor)][get<1>(coor)][get<2>(coor)-1] == 0 && cost[get<0>(coor)][get<1>(coor)][get<2>(coor)-1] > nowc+1){
            qu.push({{get<0>(coor),get<1>(coor),get<2>(coor)-1},nowc+1});
            cost[get<0>(coor)][get<1>(coor)][get<2>(coor)-1] = nowc+1;
        }
    }
}

int main(){
    fastio;
    cin >> m >> n >> h;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;j<m;k++){
                cin >> mp[i][j][k];
                if(mp[i][j][k] != 1){
                    cost[i][j][k] = 9999999;
                }
                if(mp[i][j][k] == 1){
                    qu.push({{i,j,k},0});
                }
            }
        }
    }
    bfs();
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;j<m;k++){
                if(mp[i][j][k] == 0){
                    mmx = max(mmx,cost[i][j][k]);
                }
            }
        }
    }
    if(mmx == 9999999){
        cout << -1;
    }else{
        cout << mmx;
    }
}