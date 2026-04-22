#include <bits/stdc++.h>
#define inf 999999999

using namespace std;

vector<pair<int,pair<int,int>>> vc[110]; // now time cost
int dp[110][10010];
int chktime[110][30000];
int mmn = inf;
int t, n, m, k;

void dijkstra(int start, int end) {
    priority_queue<pair<int,pair<int,int>>> pq; // -time next cost
    pq.push({-0, {start, 0}});
    dp[start][0] = 0;

    while (!pq.empty()) {
        int now = pq.top().second.first;
        int cost = pq.top().second.second;
        int time = -pq.top().first;
        pq.pop();

        if (now == n && cost <= m) {mmn = min(time, mmn);}
        if (dp[now][cost] < time || chktime[now][time] < cost) {continue;}

        for (auto& i : vc[now]) {
            int next = i.first;
            int ncost = i.second.second;
            int ntime = i.second.first;
            if (cost + ncost > m) {continue;}
            if (dp[next][cost + ncost] > dp[now][cost] + ntime && chktime[next][dp[now][cost] + ntime] > cost+ncost) {
                dp[next][cost + ncost] = dp[now][cost] + ntime;
                chktime[next][dp[now][cost] + ntime] = cost+ncost;
                pq.push({-dp[next][cost + ncost],{next, cost + ncost}});
            }
        }
    }
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &k);

        for (int i = 0; i <= n; i++) {
            vc[i].clear();
            for (int j = 0; j <= m; j++) {
                dp[i][j] = inf;
            }
            for (int j = 0; j <= 20000; j++) {
                chktime[i][j] = inf;
            }
        }

        for (int i = 0; i < k; i++) {
            int u, v, c, t;
            scanf("%d %d %d %d", &u, &v, &c, &t);
            vc[u].push_back({v, {t, c}});
        }

        mmn = inf;
        dijkstra(1, n);

        if (mmn == inf) {
            printf("Poor KCM\n");
        } else {
            printf("%d\n", mmn);
        }
    }
    return 0;
}