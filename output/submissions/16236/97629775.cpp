#include<bits/stdc++.h>

using namespace std;

int n;
int mp[100][100];
int visited[100][100];
pair<int,int> last;

queue<pair<pair<int,int>,int>> qu;
pair<pair<int,int>,int> chk;
int sharkSize = 2;
int allTime = 0;
int ate = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mp[i][j];
            if(mp[i][j] == 9){
                last = {i,j};
            }
        }
    }
    while(1){
        memset(visited,0,sizeof(visited));
        while(!qu.empty()){
            qu.pop();
        }
        chk = {{99999,99999},99999};
        qu.push({last,0});
        visited[last.first][last.second] = 1;
        int flag = 0;
        while(!qu.empty()){
            int i = qu.front().first.first;
            int j = qu.front().first.second;
            int cnt = qu.front().second;
            qu.pop();
            if(cnt > chk.second){break;}
            if(mp[i][j] && mp[i][j] < sharkSize && (chk.first.first > i||(chk.first.first == i && chk.first.second > j)) && chk.second >= cnt){
                flag = 1;
                chk = {{i,j},cnt};
                continue;
            }
            if(i-1 >= 0 && mp[i-1][j] <= sharkSize && !visited[i-1][j]){
                visited[i-1][j] = 1;
                qu.push({{i-1,j},cnt+1});
            }
            if(j-1 >= 0 && mp[i][j-1] <= sharkSize && !visited[i][j-1]){
                visited[i][j-1] = 1;
                qu.push({{i,j-1},cnt+1});
            }
            if(j+1 < n && mp[i][j+1] <= sharkSize && !visited[i][j+1]){
                visited[i][j+1] = 1;
                qu.push({{i,j+1},cnt+1});
            }
            if(i+1 < n && mp[i+1][j] <= sharkSize && !visited[i+1][j]){
                visited[i+1][j] = 1;
                qu.push({{i+1,j},cnt+1});
            }
        }
        if(!flag){
            break;
        }else{
            allTime += chk.second;
            ate++;
            if(ate == sharkSize){
                sharkSize++;
                ate = 0;
            }
            mp[last.first][last.second] = 0;
            last = chk.first;
            mp[chk.first.first][chk.first.second] = 9;
        }
    }
    cout << allTime;
}