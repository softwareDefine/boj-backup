#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int arr[1010][1010];
int dist[1010][1010];

int m,n;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
typedef struct sdfsdfdfsdfdsfsd{
    int x;
    int y;
}t;
queue<t> now;
int bfs(){
    queue<t> qu;
    while(!now.empty()){
        qu.push({now.front().x,now.front().y});
        dist[now.front().x][now.front().y]=0;
        now.pop();
    }
    int nx,ny;
    while(!qu.empty()){
        nx = qu.front().x;
        ny = qu.front().y;
        qu.pop();
        for(int i=0;i<4;i++){
            if( (nx + dx[i]>=0 && nx + dx[i]<m) &&(ny + dy[i]>=0 && ny + dy[i]<n)&&arr[nx+dx[i]][ny+dy[i]] == 0 && dist[nx+dx[i]][ny+dy[i]]==-1 ){
                qu.push({nx+dx[i],ny+dy[i]});
                dist[nx+dx[i]][ny+dy[i]]=dist[nx][ny]+1;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==0 && dist[i][j]==-1){
                    return -1;
            }
        }
    }
    return dist[nx][ny];
}
int main()
{
    memset(dist,-1,sizeof dist);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                 now.push({i,j});
            }
        }
    }
    int reut = bfs();
    cout << reut ;
    return 0;
}
