#include <iostream>
#include <queue>

using namespace std;
int arr[2505][2505];
int n, m;
int t;
int visited[2505][2505];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(int gy,int gx) {
    queue<pair<int, int>> qu;
    visited[gy][gx] = 1;
    qu.push({ gy,gx });
    while (!qu.empty()) {
        int y = qu.front().first;
        int x = qu.front().second;
        qu.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (ny < m && ny>= 0 && nx < n && dx[i] + x >= 0 && visited[dy[i] + y][dx[i] + x] == 0 && arr[dy[i] + y][dx[i] + x] == 1) {
                qu.push({ dy[i] + y,dx[i] + x });
                visited[dy[i] + y][dx[i] + x] = 1;
            }
        }
    }
}
int main()
{
    cin >> t;
    while (t--) {
        int q;
        int cnt = 0;
        for (int i = 0; i <= 500; i++) {
            for (int j = 0; j <= 500; j++) {
                arr[i][j] = 0;
                visited[i][j] = 0;
            }
        }
        cin >> n >> m >> q;
        for (int i = 0; i < q; i++) {
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j]==1 && visited[i][j] == 0) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}