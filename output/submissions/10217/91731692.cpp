#include <bits/stdc++.h>
#define inf 999999999

using namespace std;

struct node {
    int now;
    int cost;
    int time;
};

struct compare {
    bool operator()(const node& e1, const node& e2) {
        if (e1.time == e2.time) {
            return e1.cost > e2.cost;
        }
        return e1.time > e2.time;
    }
};

vector<node> vc[110];
int dp[110][10010];
int mmn = inf;
int t, n, m, k;

void dijkstra(int start, int end) {
    priority_queue<node, vector<node>, compare> pq;
    pq.push({start, 0, 0});
    dp[start][0] = 0;

    while (!pq.empty()) {
        int now = pq.top().now;
        int cost = pq.top().cost;
        int time = pq.top().time;
        pq.pop();

        if (now == n && cost <= m) {mmn = min(time, mmn);}
        if (dp[now][cost] < time) {continue;}

        for (auto& i : vc[now]) {
            int next = i.now;
            int ncost = i.cost;
            int ntime = i.time;
            if (cost + ncost > m) {continue;}
            if (dp[next][cost + ncost] > dp[now][cost] + ntime) {
                dp[next][cost + ncost] = dp[now][cost] + ntime;
                pq.push({next, cost + ncost, dp[now][cost] + ntime});
            }
        }
    }
}

int main() {
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 110; i++) {
            vc[i].clear();
            for (int j = 0; j < 10010; j++) {
                dp[i][j] = inf;
            }
        }
        scanf("%d %d %d", &n, &m, &k);

        for (int i = 0; i < k; i++) {
            int u, v, c, t;
            scanf("%d %d %d %d", &u, &v, &c, &t);
            vc[u].push_back({v, c, t});
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