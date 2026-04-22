#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m;
char arr[110][110];
int visited[110][110];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

typedef struct hi {
    int x;
    int y;
    int c;
}h;

int bfs(int nx,int ny,int cnt) {
    queue<h> qu;
    
    qu.push({nx,ny,1});
    visited[nx][ny] = 1;
    while (!qu.empty()) {
        nx = qu.front().x;
        ny = qu.front().y;
        cnt = qu.front().c;
        //printf("%d %d %d\n", nx, ny, cnt);
        if (nx == n-1 && ny == m-1) {
            printf("%d", cnt);
            return 1; 
        }
        qu.pop();
        for (int i = 0; i < 4; i++) {
            if (arr[nx + dx[i]][ny + dy[i]] == '1' && visited[nx + dx[i]][ny + dy[i]]!=1 && (nx + dx[i]>=0 && nx + dx[i]<n) &&(ny + dy[i]>=0 && ny + dy[i]<m)) {
                qu.push({ nx + dx[i], ny + dy[i],cnt+1});
                visited[nx + dx[i]][ny + dy[i]] = 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }
    bfs(0, 0, 0);
}