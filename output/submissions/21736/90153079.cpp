#include<iostream>
#include<string>
#include<queue>

using namespace std;

int n,m;

bool visited[700][700];
string map[700];
pair<int,int> mylocation;
queue<pair<int,int>> qu;

int bfs(){
    int cnt = 0;
    qu.push(mylocation);
    visited[mylocation.first][mylocation.second] = 1;
    while(!qu.empty()){
        int x = qu.front().first;
        int y = qu.front().second;
        if(map[x][y] == 'P'){ cnt ++; }
        qu.pop();
        if(x+1 < n && map[x+1][y]!='X' && !visited[x+1][y]){
            visited[x+1][y] =1;
            qu.push({x+1,y});
        }
        if(x-1 >= 0 && map[x-1][y]!='X' && !visited[x-1][y]){
            visited[x-1][y] =1;
            qu.push({x-1,y});
        }
        if(y+1 < m && map[x][y+1]!='X' && !visited[x][y+1]){
            visited[x][y+1] =1;
            qu.push({x,y+1});
        }
        if(y-1 >= 0 && map[x][y-1]!='X' && !visited[x][y-1]){
            visited[x][y-1] =1;
            qu.push({x,y-1});
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> map[i];
        for(int j=0;j<m;j++){
            if(map[i][j] == 'I'){
                mylocation.first = i; // y
                mylocation.second = j; // x
            }
        }
    }
    int a = bfs();
    if(a){
        cout << a;
    }else{
        cout << "TT";
    }
}