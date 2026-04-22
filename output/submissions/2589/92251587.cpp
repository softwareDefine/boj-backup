#include<bits/stdc++.h>

using namespace std;

int l,w;

string mp[100];
int cost[100][100];
int mmx;

void go(int x,int y){
    for(int i=0;i<l;i++){
        for(int j=0;j<w;j++){
            cost[i][j] = -99999999;
        }
    }
    queue<pair<pair<int,int>,int>> qu;
    qu.push({{x,y},0});
    cost[x][y] = 0;
    while(!qu.empty()){
        int nx = qu.front().first.first;
        int ny = qu.front().first.second;
        int ncost = qu.front().second;
        mmx = max(mmx,ncost);
        qu.pop();
        if(nx+1 < l && mp[nx+1][ny] == 'L' && cost[nx+1][ny] == -99999999){
           cost[nx+1][ny] =  ncost+1;
           qu.push({{nx+1,ny},ncost+1});
        }
        if(nx-1 >= 0 && mp[nx-1][ny] == 'L' && cost[nx-1][ny] == -99999999){
            cost[nx-1][ny] =  ncost+1;
            qu.push({{nx-1,ny},ncost+1});
        }
        if(ny+1 < w && mp[nx][ny+1] == 'L' && cost[nx][ny+1] == -99999999){
            cost[nx][ny+1] =  ncost+1;
            qu.push({{nx,ny+1},ncost+1});
        }
        if(ny-1 >= 0 && mp[nx][ny-1] == 'L' && cost[nx][ny-1] == -99999999){
            cost[nx][ny-1] =  ncost+1;
            qu.push({{nx,ny-1},ncost+1});
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> l >> w;
    for(int i=0;i<l;i++){
        cin >> mp[i];
    }
    for(int i=0;i<l;i++){
        for(int j=0;j<w;j++){
            if(mp[i][j] == 'L'){
               go(i,j);
            }
        }
    }
    cout << mmx;
}