#include <bits/stdc++.h>

using namespace std;
int n,m;
int cost[2][2000][2000];
int mp[2000][2000];

int solve(){
    queue<pair<pair<int,int>,pair<int,int>>> qu; // n m  cost isUsed
    cost[0][1][1] = 0;
    qu.push({{1,1},{0,0}});
    while(!qu.empty()){
        int x = qu.front().first.first;
        int y = qu.front().first.second;
        int ncost = qu.front().second.first;
        int isUsed = qu.front().second.second;
        //cout << x << ' ' << y << '\n';
        qu.pop();
        if(isUsed == 0){
            if(x+1 <= n){
                if(mp[x+1][y] == 0){
                    if(cost[0][x+1][y] > ncost + 1){
                        cost[0][x+1][y] = ncost + 1;
                        qu.push({{x+1,y},{ cost[0][x+1][y],0}});
                    }
                }else{
                    if(cost[1][x+1][y] > ncost + 1){
                        cost[1][x+1][y] = ncost + 1;
                        qu.push({{x+1,y},{ cost[1][x+1][y],1}});
                    }
                }
            }
            if(x - 1 > 0){
                if(mp[x-1][y] == 0){
                    if(cost[0][x-1][y] > ncost + 1){
                        cost[0][x-1][y] = ncost + 1;
                        qu.push({{x-1,y},{ cost[0][x-1][y],0}});
                    }
                }else{
                    if(cost[1][x-1][y] > ncost + 1){
                        cost[1][x-1][y] = ncost + 1;
                        qu.push({{x-1,y},{ cost[1][x-1][y],1}});
                    }
                }
            }
            if(y +1 <= m){
                if(mp[x][y+1] == 0){
                    if(cost[0][x][y+1] > ncost + 1){
                        cost[0][x][y+1] = ncost + 1;
                        qu.push({{x,y+1},{ cost[0][x][y+1],0}});
                    }
                }else{
                    if(cost[1][x][y+1] > ncost + 1){
                        cost[1][x][y+1] = ncost + 1;
                        qu.push({{x,y+1},{ cost[1][x][y+1],1}});
                    }
                }
            }
            if(y - 1 > 0){
                if(mp[x][y-1] == 0){
                    if(cost[0][x][y-1] > ncost + 1){
                        cost[0][x][y-1] = ncost + 1;
                        qu.push({{x,y-1},{ cost[0][x][y-1],0}});
                    }
                }else{
                    if(cost[1][x][y-1] > ncost + 1){
                        cost[1][x][y-1] = ncost + 1;
                        qu.push({{x,y-1},{ cost[1][x][y-1],1}});
                    }
                }
            }
        }else{
            if(x+1 <= n && mp[x+1][y] == 0 && cost[1][x+1][y] > ncost + 1){ 
                cost[1][x+1][y] = ncost + 1;
                qu.push({{x+1,y},{ cost[1][x+1][y],1}});
            }
            if(x - 1 > 0 && mp[x-1][y] == 0 && cost[1][x-1][y] > ncost + 1){
                cost[1][x-1][y] = ncost + 1;
                qu.push({{x-1,y},{ cost[1][x-1][y],1}});
            }
            if(y +1 <= m && mp[x][y+1] == 0 && cost[1][x][y+1] > ncost + 1){
                cost[1][x][y+1] = ncost + 1;
                qu.push({{x,y+1},{ cost[1][x][y+1],1}});
            }
            if(y - 1 > 0 &&  mp[x][y-1] == 0 && cost[1][x][y-1] > ncost + 1){
                cost[1][x][y-1] = ncost + 1;
                qu.push({{x,y-1},{ cost[1][x][y-1],1}});
            }
        }
    }
    return min(cost[1][n][m], cost[0][n][m]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<2000;i++){
        for(int j=0;j<2000;j++){
            cost[0][i][j] = 9999999;
            cost[1][i][j] = 9999999;
        }
    }
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<m;j++){
            mp[i+1][j+1] = str[j] - '0';
        }
    }
    int ans = solve();
    if(ans == 9999999){
        cout << -1;
    }else{
        cout << ans+1;
    }
    return 0;
}