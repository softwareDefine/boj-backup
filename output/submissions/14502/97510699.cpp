#include <bits/stdc++.h>

using namespace std;

int n,m;
int mp[50][50];

int cnt;
queue<pair<int,int>> qu;

int mmx;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mp[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int a=0;a<n;a++){
                for(int b=0;b<m;b++){
                    for(int x=0;x<n;x++){
                        for(int y=0;y<m;y++){
                            int tmp[50][50];
                            if(mp[i][j]|| mp[a][b]|| mp[x][y]){
                                continue;
                            }
                            for(int k=0;k<n;k++){
                                for(int r=0;r<m;r++){
                                    tmp[k][r] = mp[k][r];
                                    if(mp[k][r] == 2){
                                        qu.push({k,r});
                                    }
                                }
                            }
                            tmp[i][j] = 8;
                            if(tmp[a][b] == 8){continue;}
                            tmp[a][b] = 8;
                            if(tmp[x][y] == 8){continue;}
                            tmp[x][y] = 8;
                            while(!qu.empty()){
                                int ny = qu.front().first;
                                int nx = qu.front().second;
                                qu.pop();
                                if(nx+1 < m && tmp[ny][nx+1]  == 0){
                                    qu.push({ny,nx+1});
                                    tmp[ny][nx+1] = 2;
                                }
                                if(nx-1 >= 0 && tmp[ny][nx-1]  == 0){
                                    qu.push({ny,nx-1});
                                    tmp[ny][nx-1] = 2;
                                }
                                if(ny+1 < n && tmp[ny+1][nx]  == 0){
                                    qu.push({ny+1,nx});
                                    tmp[ny+1][nx] = 2;
                                }
                                if(ny-1 >= 0 && tmp[ny-1][nx] == 0){
                                    qu.push({ny-1,nx});
                                    tmp[ny-1][nx] = 2;
                                }
                            }
                            cnt = 0;
                            for(int k=0;k<n;k++){
                                for(int r=0;r<m;r++){
                                    if(!tmp[k][r]){
                                        cnt++;
                                    }
                                }
                            }
                            mmx = max(mmx,cnt);
                        }
                    }
                }
            }
        }
    }
    cout << mmx;
}