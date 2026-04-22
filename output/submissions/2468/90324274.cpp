#define fastio cin.tie(0)->sync_with_stdio(0)
#include <bits/stdc++.h>

using namespace std;

int n;
int mp[110][110];
int visited[110][110];
int mmx = 0;
queue<pair<int,int>> qu;

void bfs(pair<int,int> start,int limit){
    qu.push(start);
    visited[start.first][start.second] = 1;
    while(!qu.empty()){
        pair<int,int> coor = qu.front();
        qu.pop();
        if(coor.first + 1 < n && mp[coor.first+1][coor.second] > limit && !visited[coor.first+1][coor.second]){
            visited[coor.first+1][coor.second] = 1;
            qu.push({coor.first+1,coor.second});
        }
        if(coor.first - 1 > -1 && mp[coor.first-1][coor.second] > limit && !visited[coor.first-1][coor.second]){
            visited[coor.first-1][coor.second] = 1;
            qu.push({coor.first-1,coor.second});
        }
        if(coor.second + 1 < n && mp[coor.first][coor.second+1] > limit && !visited[coor.first][coor.second+1]){
            visited[coor.first][coor.second+1] = 1;
            qu.push({coor.first,coor.second+1});
        }
        if(coor.second - 1 > -1 && mp[coor.first][coor.second-1] > limit && !visited[coor.first][coor.second-1]){
            visited[coor.first][coor.second-1] = 1;
            qu.push({coor.first,coor.second-1});
        }
    }
}

int main(){
    fastio;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mp[i][j];
        }
    }
    for(int i=0;i<=100;i++){
        int cnt = 0;
        while(!qu.empty()){
            qu.pop();
        }
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                visited[x][y] = 0;
            }
        }
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                if(!visited[x][y] && mp[x][y] > i){
                    bfs({x,y},i);
                    cnt++;
                }
            }
        }
        mmx = max(mmx,cnt);
    }
    cout << mmx;
}