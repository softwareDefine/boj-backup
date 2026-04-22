#define x first
#define y second
#include <bits/stdc++.h>

using namespace std;
using point = pair<int, int>;

int n;

vector<point> lines;

vector<int> xcoor;
vector<int> ycoor;

int xbound[2200][2200]; int ybound[2200][2200];
int visited[2200][2200];

int ans;

int bfs(int i, int j){
    queue<point> qu;
    int cnt = 0, mmnx = 9999, mmxx = -1, mmny = 9999, mmxy = -1;  
    qu.push({i, j});
    visited[i][j] = 1;
    while(!qu.empty()){
        auto [x, y] = qu.front();
        cnt += 1;
        mmnx = min(mmnx, x); mmxx = max(mmxx, x);
        mmny = min(mmny, y); mmxy = max(mmxy, y);
        qu.pop();
        if(x-1 >= 0 && !ybound[x][y] && !visited[x-1][y]){
            visited[x-1][y] = 1;
            qu.push({x-1, y});
        }
        if(x+1 <= 2100 && !ybound[x+1][y] && !visited[x+1][y]){
            visited[x+1][y] = 1;
            qu.push({x+1, y});
        }
        if(y-1 >= 0 && !xbound[x][y] && !visited[x][y-1]){
            visited[x][y-1] = 1;
            qu.push({x, y-1});
        }
        if(y+1 <= 2100 && !xbound[x][y+1] && !visited[x][y+1]){
            visited[x][y+1] = 1;
            qu.push({x, y+1});
        }
    }
    return ((mmxx - mmnx + 1) * (mmxy - mmny + 1) == cnt);
}

int main(){
    cin >> n;
    lines.resize(n);
    for(auto &[a, b] : lines){
        cin >> a >> b;
        xcoor.push_back(a); xcoor.push_back(b);
    }
    sort(xcoor.begin(), xcoor.end()); 
    //sort(ycoor.begin(), ycoor.end());
    xcoor.erase(unique(xcoor.begin(), xcoor.end()), xcoor.end());
    //ycoor.erase(unique(ycoor.begin(), ycoor.end()), ycoor.end());
    for(auto &[a, b] : lines){
        a = lower_bound(xcoor.begin(), xcoor.end(), a) - xcoor.begin();
        b = lower_bound(xcoor.begin(), xcoor.end(), b) - xcoor.begin();
    }
    for(int p = 0; p < n-1; p++){
        auto now = lines[p], next = lines[p+1];
        if(now.x == next.x){
            if(now.y > next.y){
                for(int j = now.y-1; j >= next.y; j--){
                    ybound[now.x][j] = 1;
                }
            }else{
                for(int j = now.y; j < next.y; j++){
                    ybound[now.x][j] = 1;
                }
            }
        }else if(now.y == next.y){
            if(now.x > next.x){
                for(int i = now.x-1; i >= next.x; i--){
                    xbound[i][now.y] = 1;
                }
            }else{
                for(int i = now.x; i < next.x; i++){
                    xbound[i][now.y] = 1;
                }
            }
        }
    }
    // 1000*1000칸 순회하면서 방문안한칸은 BFS돌림
        //- BFS돌릴 때에는 최소 최대 x,y와 방문한 칸 수를 조사해서 같은 지 조사 +1함
    for(int i = 0; i <= 2100; i++){
        for(int j = 0; j <= 2100; j++){
            if(!visited[i][j]  && xbound[i][j] && ybound[i][j]){
                ans += bfs(i,j);
            }
        }
    }
    cout << ans;
}