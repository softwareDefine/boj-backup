#include <bits/stdc++.h>

using namespace std;

int n,m;

string mp[2000];
int visited[2000][2000];
int cnt = 1;

int ans;

int bfs(int si,int sj){
    queue<pair<int,int>> qu;
    qu.push({si,sj});;
    visited[si][sj] = cnt;
    while(!qu.empty()){
        int i = qu.front().first;
        int j = qu.front().second;
        qu.pop();
        switch(mp[i][j]){
            case 'D':
                if(i+1 < n){
                    if(visited[i+1][j] > cnt){
                        visited[i+1][j] = cnt;
                        qu.push({i+1,j});
                    }else if(visited[i+1][j] == cnt){
                        return  1;
                    }else{
                        return 0;
                    }
                }
                break;
            case 'R':
                if(j+1 < m){
                    if(visited[i][j+1] > cnt){
                        visited[i][j+1] = cnt;
                        qu.push({i,j+1});
                    }else if(visited[i][j+1] == cnt){
                        return  1;
                    }else{
                        return 0;
                    }
                }
                break;
            case 'L':
                if(j-1 >= 0){
                    if(visited[i][j-1] > cnt){
                        visited[i][j-1] = cnt;
                        qu.push({i,j-1});
                    }else if(visited[i][j-1] == cnt){
                        return  1;
                    }else{
                        return 0;
                    }
                }
                break;
            case 'U':
                if(i-1 >= 0){
                    if(visited[i-1][j] > cnt){
                        visited[i-1][j] = cnt;
                        qu.push({i-1,j});
                    }else if(visited[i-1][j] == cnt){
                        return  1;
                    }else{
                        return 0;
                    }
                }
                break;
        }
    }
    return 1;
}

int main(){
    for(int i=0;i<2000;i++){
        for(int j=0;j<2000;j++){
            visited[i][j] = 99999999;
        }
    }
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> mp[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j] == 99999999){
                if(bfs(i,j)){
                    ans += 1;
                    cnt++;
                }
            }
        }
    }
    cout << ans;
}