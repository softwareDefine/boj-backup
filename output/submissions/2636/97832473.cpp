#include <iostream>
#include <algorithm>
#include <queue> 


using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int visited[110][110];
int n, m;
int arr[110][110];
int ans = 0;
queue<pair<int, int>> qu;
// 바깥 공기 3
// 안쪽 공기 0
// 치즈 1
bool is_melt(int y, int x)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        if (x + dx[i] >= 0 && x + dx[i] < m && y + dy[i] >= 0 && y + dy[i] < n && (arr[y + dy[i]][x + dx[i]] == 3))
        {
            cnt++;
        }
    }
    return (cnt >= 1);
}
void air() {
    int aisted[110][110] = { 0, };
    queue<pair<int, int>> aq;
    aq.push({ 107,107 });
    aisted[107][107] = 1;
    while (!aq.empty()) {
        int x = aq.front().first;
        int y = aq.front().second;
        arr[x][y] = 3;
        aq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (ny >= 0 && ny < 110 && nx >= 0 && nx < 110 && arr[nx][ny] != 1 && aisted[nx][ny] != 1) {
                aq.push({ nx,ny });
                aisted[nx][ny] = 1;
            }
        }
    }
}
/*int bfs()
{
    int cnt = 0;
    while (!qu.empty()) {
        int y = qu.front().first.second;
        int x = qu.front().first.first;
        arr[x][y] = 3;
        air();
        cnt = qu.front().second;
        qu.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (ny >= 0 && ny < m && nx >= 0 && nx < n && arr[nx][ny] == 1 && visited[nx][ny] != 1 && is_melt(nx, ny)) {
                qu.push({ { nx,ny },cnt + 1 });
                visited[nx][ny] = 1;
            }
        }
    }
    return cnt;
}*/
bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 3) {
                return 1;
            }
        }
    }
    return 0;
}

int before;



int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    while (check()) {
        ans++;
        air();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //cout << arr[i][j] <<' ';
                if (arr[i][j] == 1 && is_melt(i, j)) {
                    qu.push({ i,j });
                    visited[i][j] = 1;
                }
            }
            //cout << '\n';
        }
        //cout << '\n';
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j] == 1){
                    cnt++;
                }
            }
        }
        if(cnt){
            before = cnt;
        }
        int szze = qu.size();
        while (!qu.empty()) {
            int x = qu.front().first;
            int y = qu.front().second;
            arr[x][y] = 3;
            qu.pop();
        }
        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << arr[i][j];
            }
            cout << '\n';
        }
        cout << ans;
        cout << '\n';*/
    }
    cout << ans << '\n';
    cout << before;
    return 0;
}