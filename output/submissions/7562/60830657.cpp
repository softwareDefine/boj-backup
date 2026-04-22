#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int cnt[301][301];
int num;

int l;
int nx,ny,gx,gy;
int plag[311][311];

queue<pair<int,int>> qu;
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};

void ch(int x,int y){
    qu.push({x,y});
    plag[x][y]=1;
    while(!qu.empty()){
        int sx = qu.front().first;
        int sy = qu.front().second;
        qu.pop();

        if(sx == gx && sy == gy){
            cout << cnt[sx][sy] << endl;

            while(!qu.empty()){
                qu.pop();
            }
            break;
        }
        for(int i=0;i<8;i++){
            int ax = sx + dx[i];
            int ay = sy + dy[i];

            if(ax >= 0 && ax < l && ay >= 0 && ay < l){
                if(plag[ax][ay]==0){
                    plag[ax][ay]=1;
                    cnt[ax][ay]=cnt[sx][sy]+1;
                    qu.push({ax,ay});
                }
            }
        }
    }
}


int main(){
    cin >> num ;
    for(int i=0;i<num;i++){
        cin >> l;
        cin >> nx >> ny;
        cin >> gx >> gy;
        ch(nx,ny);
        memset(cnt, 0, sizeof(cnt));
        memset(plag, 0, sizeof(plag));
    }
}
