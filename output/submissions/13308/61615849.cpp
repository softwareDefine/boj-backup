#include <iostream>
#include <vector>
#include <queue>
#define inf 999999999

using namespace std;

int n, m;
int cost[10010];
int dist[3010][5000];
int s, e;
int mmn = 9999999;
vector<pair<int,int>> vc[10010];

void dak(int s, int e) {
	priority_queue<pair<int,pair<int, int>>> pq;
	pq.push({0,{ s,cost[s]}});
	dist[s][cost[s]] = 0;
	while (!pq.empty()) {
		int allcost = -pq.top().first;
		int now = pq.top().second.first;
		int mmnc = pq.top().second.second;
		pq.pop();
		if (dist[now][mmnc] < allcost) {
			continue;
		}
		for (auto& i : vc[now]) {
			int next = i.first;
			int nc = i.second;
			if (dist[next][(min(cost[now], mmnc))] > allcost + nc * (min(cost[now], mmnc))) {
				dist[next][(min(cost[now], mmnc))] = allcost + nc * (min(cost[now], mmnc));
				pq.push({ -(allcost + nc * (min(cost[now],mmnc))) ,{next,min(cost[now],mmnc)} });
			}
		}
	}
}

int main()
{
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
		int u, v, c;
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