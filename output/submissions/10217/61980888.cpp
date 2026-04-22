#include <iostream>
#include <vector>
#include <queue>
#define inf 999999999

using ll = long long;
using namespace std;

// 다음향하는 위치, 비용,시간
vector<pair<ll, pair<ll, ll>>> vc[110];
ll dp[110][100010]; // i번째 비용 j 일때 최소 시간
ll mmn = inf;
int t, n, m, k;

void daik(int start, int end) {
	//시간 , 위치 ,비용
	priority_queue<pair<ll, pair<ll, ll>>> pq;
	pq.push({ 0,{start,0} });
	dp[start][0] = 0;
	while (!pq.empty()) {
		ll time = -pq.top().first;
		int now = pq.top().second.first;
		ll cost = pq.top().second.second;
		pq.pop();
		if (dp[now][cost] < time) {
			continue;
		}
		for (auto& i : vc[now]) {
			int next = i.first;
			ll ncost = i.second.first;
			ll ntime = i.second.second;
			if (cost + ncost > m) {
				continue;
			}
			if (dp[next][cost + ncost] > dp[now][cost] + ntime) {
				dp[next][cost + ncost] = dp[now][cost] + ntime;
				pq.push({ -(dp[now][cost] + ntime),{next,cost + ncost} });
			}
		}
	}
}

int main()
{
	cin >> t;
	while (t--) {
		for (int i = 0; i < 110; i++) {
			vc[i].clear();
			for (int j = 0; j < 100010; j++) {
				dp[i][j] = inf;
			}
		}
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			ll u, v, c, t;
			cin >> u >> v >> c >> t;
			vc[u].push_back({ v,{c,t} });
		}
		daik(1, n);
		mmn = inf;
		for (int i = 0; i <= m; i++) {
			mmn = min(dp[n][i], mmn);
		}
		if (mmn >= inf) {
			cout << "Poor KCM" << '\n';
		}
		else {
			cout << mmn << '\n';
		}
	}
}