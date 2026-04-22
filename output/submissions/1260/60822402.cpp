#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

vector<int> vc[10001];
int n, m, v;
int x, y;
int visited[100000];
int visited2[100000];

void dfs(int now) {
    
    visited[now] = 1;
    cout << now << " ";
    int size = vc[now].size();
    for (int i = 0; i <size; i++) {
        if (visited[vc[now][i]] != 1) {
            dfs(vc[now][i]);
        }
    }
}
void bfs(int st) {
    queue<int> qu;
    int h;
    qu.push(st);
    visited2[st] = 1;
    while (!qu.empty()) {
        h = qu.front();
        cout << h <<" ";
        qu.pop();
        int size = vc[h].size();
        for (int i = 0; i < size; i++) {
           if (visited2[vc[h][i]] != 1) {
               qu.push(vc[h][i]);
               visited2[vc[h][i]] = 1;
           }
    }
    }
}

int main()
{
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        vc[x].push_back(y);
        vc[y].push_back(x);
    }
    for (int i = 0; i < m; i++) {
        if (!vc[i].empty()) {
            sort(vc[i].begin(), vc[i].end());
        }

    }
    dfs(v);
    cout << endl;
    bfs(v);
}