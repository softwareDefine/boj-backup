#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> node[1 << 22];
int vis[1 << 22];
int counter;
void dfs(int x) {
    vis[x] = 1;
    counter++;
    for (auto nxt : node[x]) {
        if (!vis[nxt]) {
            dfs(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        node[b].push_back(a);
    }
    int cnt = 0;
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            vis[j] = 0;
        }
        counter = 0;
        dfs(i);
        int ret = counter;
        if (cnt == ret) {
            ans.push_back(i);
        }
        else if (cnt < ret) {
            cnt = ret;
            ans.clear();
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans) {
        cout << x << " ";
    }
}