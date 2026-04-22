#include <iostream>
#include <vector>
#include <queue>
#define inf 9999999999

using namespace std;

int n, m, k;
int s, d;
vector<pair<int, int>> vc[300010];
int up[300010];

int dist[1010][1010];

void dik(int start, int end) {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({0,{ start,0 }});
	dist[start][0] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int now = pq.top().second.first;
		int edgeing = pq.top().second.second;
		pq.pop();
		if (edgeing == n - 1) {
			continue;
		}
		if (cost > dist[now][edgeing]) {
			continue;
		}
		for (auto& i : vc[now]) {
			int next = i.first;
			int ncost = i.second;
			if (dist[next][edgeing + 1] > dist[now][edgeing]+ncost) {
				dist[next][edgeing + 1] = dist[now][edgeing] + ncost;
				pq.push({ -(dist[now][edgeing] + ncost),{next,edgeing + 1} });
			}
		}
	}
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	for (int i = 0; i < 1010; i++) {
		for (int j = 0; j < 1010; j++) {
			if (i == 0) { break; }
			dist[i][j] = inf;
		}
	}
	cin >> n >> m >> k;
	cin >> s >> d;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		vc[u].push_back({ v,c });
		vc[v].push_back({ u,c });
	}
	for (int i = 1; i <= k; i++) {
		cin >> up[i];
		up[i] += up[i - 1];
	}
	dik(s, d);
	for (int i = 0; i <= k; i++) {
		int ans = inf;
		for (int j = 0; j <= n - 1; j++) {
			ans = min(ans, dist[d][j]+up[i]*j);
		}
		cout << ans << '\n';
	}
}