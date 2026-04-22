#include <bits/stdc++.h>

using namespace std;

int n,k;

int mp[100][100];
int visited[100][100];

int mmn = 999999999;

int bfs(){
    queue<pair<pair<int,int>,int>> qu;
    while(!qu.empty()){qu.pop();}
    if(mp[0][0] == 1 || mp[0][0] == 5){
        visited[0][0] = 1;
        qu.push({{0,0},1});
    }
    while(!qu.empty()){
        int i = qu.front().first.first;
        int j = qu.front().first.second;
        int cnt = qu.front().second;
        qu.pop();
        if(i == n-1 && j == n){
            return cnt;
        }
        switch (mp[i][j]) {
            case 0:
                if(i+1 < n && (mp[i+1][j] <=4 && mp[i+1][j] >= 2) && !visited[i+1][j]){
                    visited[i+1][j] =1;
                    qu.push({{i+1,j},cnt+1});
                }
                if(j+1 < n &&  (mp[i][j+1] == 1 || mp[i][j+1] == 3 || mp[i][j+1] == 5) && !visited[i][j+1]){
                    visited[i][j+1] =1;
                    qu.push({{i,j+1},cnt+1});
                }
                break;
            case 1:
                if(i+1 < n && (mp[i+1][j] <=4 && mp[i+1][j] >= 2) && !visited[i+1][j]){
                     visited[i+1][j] =1;
                    qu.push({{i+1,j},cnt+1});
                }
                if(j-1 >= 0 &&  (mp[i][j-1] == 0 || mp[i][j-1] == 2 || mp[i][j-1] == 5) && !visited[i][j-1]){
                    visited[i][j-1] =1;
                    qu.push({{i,j-1},cnt+1});
                }
                break;
            case 2:
                if(j+1 == n && i == n-1){
                    qu.push({{i,j+1},cnt+1});
                    continue;
                }
                if(i-1 >=0 && (mp[i-1][j] == 0 || mp[i-1][j] == 1 || mp[i-1][j] == 4) && !visited[i-1][j]){
                    visited[i-1][j] =1;
                    qu.push({{i-1,j},cnt+1});
                }if(j+1 < n && (mp[i][j+1] == 1 || mp[i][j+1] == 3 || mp[i][j+1] == 5) && !visited[i][j+1]){
                    visited[i][j+1] = 1;
                    qu.push({{i,j+1},cnt+1});
                }
                break;
            case 3:
                if(j-1 >= 0 &&  (mp[i][j-1] == 0 || mp[i][j-1] == 2 || mp[i][j-1] == 5) && !visited[i][j-1]){
                    visited[i][j-1] =1;
                    qu.push({{i,j-1},cnt+1});
                }
                if(i-1 >=0 && (mp[i-1][j] == 0 || mp[i-1][j] == 1 || mp[i-1][j] == 4) && !visited[i-1][j]){
                    visited[i-1][j] =1;
                    qu.push({{i-1,j},cnt+1});
                }
                break;
            case 4:
                if(i+1 < n && (mp[i+1][j] <=4 && mp[i+1][j] >= 2) && !visited[i+1][j]){
                     visited[i+1][j] =1;
                    qu.push({{i+1,j},cnt+1});
                }
                if(i-1 >=0 && (mp[i-1][j] == 0 || mp[i-1][j] == 1 || mp[i-1][j] == 4) && !visited[i-1][j]){
                    visited[i-1][j] =1;
                    qu.push({{i-1,j},cnt+1});
                }
                break;
            default:
                if(j+1 == n && i == n-1){
                    qu.push({{i,j+1},cnt+1});
                    continue;
                }if(j-1 >= 0 &&  (mp[i][j-1] == 0 || mp[i][j-1] == 2 || mp[i][j-1] == 5) && !visited[i][j-1]){
                    visited[i][j-1] =1;
                    qu.push({{i,j-1},cnt+1});
                }if(j+1 < n && (mp[i][j+1] == 1 || mp[i][j+1] == 3 || mp[i][j+1] == 5) && !visited[i][j+1]){
                    visited[i][j+1] = 1;
                    qu.push({{i,j+1},cnt+1});
                }
                break;
        }
    }
    return 0;
}

int main(){
    cin >> n >> k;;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mp[i][j];
        }
    }
    if(k == 0){
        int tmp = bfs();
        if(tmp!=0){
            mmn = tmp;
        }
    }else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int before = mp[i][j];
                for(int l=0;l<6;l++){
                    for(int a =0;a<n;a++){
                        for(int b=0;b<n;b++){
                            visited[a][b] = 0;
                        }
                    }
                    if(before != l){
                        mp[i][j] = l;
                        int tmp = bfs();
                        if(tmp != 0){
                            mmn = min(mmn,tmp);
                        }
                        mp[i][j] = before;
                    }
                }
            }
        }
    }
    if(mmn == 999999999){
        cout << -1;
    }else{
        cout << mmn-1;
    }
}