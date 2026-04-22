#include <iostream>
#include <vector>
#include <queue>
#define inf 999999999

using namespace std;

// 다음향하는 위치, 비용,시간
vector<pair<int, pair<int, int>>> vc[110];
int dp[110][100010]; // i번째 비용 j 일때 최소 시간
int mmn = inf;
int t, n, m, k;

void daik(int start, int end) {
	//시간 , 비용,위치
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{0,start} });
	dp[start][0] = 0;
	while (!pq.empty()) {
		int time = -pq.top().first;
		int cost = pq.top().second.first;
		int now = pq.top().second.second;
		pq.pop();
		if (dp[now][cost] < time) {
			continue;
		}
		for (auto& i : vc[now]) {
			int next = i.first;
			int ncost = i.second.first;
			int ntime = i.second.second;
			if (cost + ncost > m) {
				continue;
			}
			if (dp[next][cost + ncost] > dp[now][cost] + ntime) {
				dp[next][cost + ncost] = dp[now][cost] + ntime;
				pq.push({ -(dp[now][cost] + ntime),{cost + ncost,next} });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
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
			int u, v, c, t;
			cin >> u >> v >> c >> t;
			vc[u].push_back({ v,{c,t} });
		}
		daik(1, n);
		mmn = inf;
		for (int i = 0; i <= m; i++) {
			mmn = min(dp[n][i], mmn);
		}
		if (mmn == inf) {
			cout << "Poor KCM" << '\n';
		}
		else {
			cout << mmn << '\n';
		}
	}
}