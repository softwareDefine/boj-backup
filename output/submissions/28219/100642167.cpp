#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000 + 5;
int N, K;
vector<int> adj[MAXN];
int dp[MAXN];      // 1차원 DP
bool visited[MAXN];
int ans = 0;

void dfs(int u) {
    visited[u] = true;

    int dist1 = 0, dist2 = 0;  // 가장 큰 두 개

    for (int v : adj[u]) {
        if (visited[v]) continue;
        dfs(v);

        int next_dist = dp[v] + 1;   // v 서브트리에서 u까지

        if (next_dist > dist1) {
            dist2 = dist1;
            dist1 = next_dist;
        } else if (next_dist > dist2) {
            dist2 = next_dist;
        }
    }

    if (dist1 + dist2 >= K) {
        // 여기서 길이 K 이상의 '주유소 없는 경로'가 생김 → u에 주유소 설치
        ans++;
        dp[u] = -1;   // 위로 더 안 올라가게 끊기
    } else {
        dp[u] = dist1; // 가장 긴 한 팔만 위로 올림
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);
    cout << ans << "\n";
}
