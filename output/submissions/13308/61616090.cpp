#include <iostream>
#include <vector>
#include <queue>
#define inf 999999999999

using ll = long long;
using namespace std;

ll n, m;
ll cost[10010];
ll dist[3010][5000];
ll s, e;
ll mmn = inf;
vector<pair<ll, ll>> vc[10010];

void dak(ll s, ll e) {
	priority_queue<pair<ll, pair<ll, ll>>> pq;
	pq.push({ 0,{ s,cost[s]} });
	dist[s][cost[s]] = 0;
	while (!pq.empty()) {
		ll allcost = -pq.top().first;
		ll now = pq.top().second.first;
		ll mmnc = pq.top().second.second;
		pq.pop();
		if (dist[now][mmnc] < allcost) {
			continue;
		}
		for (auto& i : vc[now]) {
			ll next = i.first;
			ll nc = i.second;
			if (dist[next][(min(cost[now], mmnc))] > allcost + nc * (min(cost[now], mmnc))) {
				dist[next][(min(cost[now], mmnc))] = allcost + nc * (min(cost[now], mmnc));
				pq.push({ -(allcost + nc * (min(cost[now],mmnc))) ,{next,min(cost[now],mmnc)} });
			}
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 0; i < 3000; i++) {
		for (int j = 0; j <= 2510; j++) {
			dist[i][j] = inf;
		}
	}
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	for (int i = 0; i < m; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		vc[u].push_back({ v,c });
		vc[v].push_back({ u,c });
	}
	dak(1, n);
	for (int i = 1; i <= 2510; i++) {
		mmn = min(mmn, dist[n][i]);
	}
	cout << mmn;
}