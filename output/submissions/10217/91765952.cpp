#include <bits/stdc++.h>
#define inf 999999999

using namespace std;

vector<pair<int,pair<int,int>>> vc[110]; // now time cost
int dp[110][30010];
int mmn = inf;
int t, n, m, k;

int cmp(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b){
    return a.second.second < b.second.second;
}

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
        if (dp[now][cost] < time) {continue;}

        for (auto& i : vc[now]) {
            int next = i.first;
            int ncost = i.second.second;
            int ntime = i.second.first;
            if (cost + ncost > m) {continue;}
            if (dp[next][cost + ncost] > dp[now][cost] + ntime && cost + ncost <= m) {
                dp[next][cost + ncost] = dp[now][cost] + ntime;
                for(int i = cost+ncost+1 ; i<=m;i++){
                    if(dp[next][i] > dp[now][cost] + ntime) dp[next][i] = dp[now][cost] + ntime;
                    else break;
                }
                pq.push({-dp[next][cost + ncost],{next, cost + ncost}});
            }
        }
    }
}

int main() {
    scanf("%d", &t);
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < 110; i++) {
        vc[i].clear();
        for (int j = 0; j <= 30000; j++) {
            dp[i][j] = inf;
        }
    }

     for (int i = 0; i < k; i++) {
        int u,v,c,t;
        cin >> u >> v >> c >> t;
        vc[u].push_back({v, {t, c}});
    }
    for(int i=0;i<=n;i++){
        sort(vc[i].begin(),vc[i].end(),cmp);
    }

    mmn = inf;
    dijkstra(1, n);

    if (mmn == inf) {
        printf("Poor KCM\n");
    } else {
        printf("%d\n", mmn);
    }
    while(1){}
    return 0;
}