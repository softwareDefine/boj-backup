#include <bits/stdc++.h>

using namespace std;

int n;
string mp[100];
pair<int,int> mmn[100][100];
void bfs(){
    queue<pair<pair<int,int>,pair<int,int>>> qu;
    qu.push({{0,0},{0,0}});
    mmn[0][0] = {0,0};
    while(!qu.empty()){
        int y = qu.front().first.first;
        int x = qu.front().first.second;
        int used = qu.front().second.first;
        int cnt = qu.front().second.second;
        qu.pop();
        if(y+1 < n){
            if(mp[y+1][x] == '0' && (mmn[y+1][x].first > used+1 || (mmn[y+1][x].first == used+1 &&mmn[y+1][x].second > cnt+1))){
                mmn[y+1][x] = {used+1,cnt+1};
                qu.push({{y+1,x},{used+1,cnt+1}});
            }else if(mp[y+1][x] == '1' && (mmn[y+1][x].first > used || (mmn[y+1][x].first == used &&mmn[y+1][x].second > cnt+1))){
                mmn[y+1][x] = {used,cnt+1};
                qu.push({{y+1,x},{used,cnt+1}});
            }
        }
        if(x+1 < n){
            if(mp[y][x+1] == '0' && (mmn[y][x+1].first > used+1 || (mmn[y][x+1].first == used+1 &&mmn[y][x+1].second > cnt+1))){
                mmn[y][x+1] = {used+1,cnt+1};
                qu.push({{y,x+1},{used+1,cnt+1}});
            }else if(mp[y][x+1] == '1' && (mmn[y][x+1].first > used || (mmn[y][x+1].first == used &&mmn[y][x+1].second > cnt+1))){
                mmn[y][x+1] = {used,cnt+1};
                qu.push({{y,x+1},{used,cnt+1}});
            }
        }
        if(y-1 >= 0){
            if(mp[y-1][x] == '0' && (mmn[y-1][x].first > used+1 || (mmn[y-1][x].first == used+1 &&mmn[y-1][x].second > cnt+1))){
                mmn[y-1][x] = {used+1,cnt+1};
                qu.push({{y-1,x},{used+1,cnt+1}});
            }else if(mp[y-1][x] == '1' && (mmn[y-1][x].first > used || (mmn[y-1][x].first == used &&mmn[y-1][x].second > cnt+1))){
                mmn[y-1][x] = {used,cnt+1};
                qu.push({{y-1,x},{used,cnt+1}});
            }
        }
        if(x-1 >= 0){
            if(mp[y][x-1] == '0' && (mmn[y][x-1].first > used+1 || (mmn[y][x-1].first == used+1 &&mmn[y][x-1].second > cnt+1))){
                mmn[y][x-1] = {used+1,cnt+1};
                qu.push({{y,x-1},{used+1,cnt+1}});
            }else if(mp[y][x-1] == '1' && (mmn[y][x-1].first > used || (mmn[y][x-1].first == used &&mmn[y][x-1].second > cnt+1))){
                mmn[y][x-1] = {used,cnt+1};
                qu.push({{y,x-1},{used,cnt+1}});
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            mmn[i][j] = {9999,9999};
        }
    }
    for(int i=0;i<n;i++){
        cin >> mp[i];
    }
    bfs();
    cout << mmn[n-1][n-1].first;
}