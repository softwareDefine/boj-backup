#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>


using namespace std;

int cnt1[350];
int sc;
int arr[350][350];
int visited[350][350];
int num;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int tx,ty;
typedef struct hi{
    int x;
    int y;
    int c;
}h;

void bfs(int qx,int qy,int acnt){
    queue<h> qu;
    qu.push({qx,qy,1});
    visited[qx][qy] =1;
    int nx,ny,cnt;
    while(!qu.empty()){
        nx = qu.front().x;
        ny = qu.front().y;
        cnt = qu.front().c;
        qu.pop();
        for(int i=0;i<4;i++){
            if((arr[nx+dx[i]][ny+dy[i]] == 1 && visited[nx+dx[i]][ny+dy[i]]==0) &&(nx + dx[i]>=0 && nx + dx[i]<num) &&(ny + dy[i]>=0 && ny + dy[i]<num)){
                qu.push({nx+dx[i],ny+dy[i],cnt+1});
                visited[nx+dx[i]][ny+dy[i]] = 1;
                cnt1[sc]++;
            }
        }
    }
    sc++;
}
int main()
{
    cin >> num;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            scanf("%1d",&arr[i][j]);
        }

    }
     for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(arr[i][j]==1 && visited[i][j]==0){
                bfs(i,j,0);
            }
        }
    }
    cout << sc << '\n';
    sort(cnt1,cnt1+sc);
    for(int i=0;i<sc;i++){
        cout << cnt1[i]+1 <<'\n';
    }
    return 0;
}
