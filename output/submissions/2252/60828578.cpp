#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,inDegree[100010];
vector<int> vertex[100010];

void topologySort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (q.empty()) {
            cout << "사이클 발생";
            return;
        }
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (int j = 0; j < vertex[x].size(); j++) {
            int y = vertex[x][j];
            if (--inDegree[y] == 0) {
                q.push(y);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vertex[a].push_back({ b });
        inDegree[b]++;
    }
    topologySort();
    
}