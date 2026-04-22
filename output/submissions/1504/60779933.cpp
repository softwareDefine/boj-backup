#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n, m;
int u, v;
int ans= 9999999;
typedef struct h {
	int now;
	int befor;
	int sum;
	int uc;
	int uv;
}p;
vector<pair<int, int>> vc[100010];
int dist[1010];
void daijestar(int st) {
	memset(dist, 9999999, sizeof dist);
	priority_queue<pair<int, int>> pq;
	dist[st] = 0;
	pq.push({ st,0 });
	while (!pq.empty()) {
		int now = pq.top().first;
		int val = -pq.top().second;
		pq.pop();
		if (dist[now] < val) {
			continue;
		}
		for (auto x : vc[now]) {
			int nx = x.first;
			int nc = val+x.second;
			if (dist[nx] > nc) {
				dist[nx] = nc;
				pq.push({ nx,-nc });
			}
		}
	}
}
int sum1,sum2;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int st, ed, val;
		cin >> st >> ed >>  val;
		vc[st].push_back({ed,val});
		vc[ed].push_back({ st,val });
	}
	cin >> u >> v;
	daijestar(1);
	sum1 += dist[u];
	sum2 += dist[v];
	daijestar(u);
	sum1 += dist[v];
	sum2 += dist[n];
	daijestar(v);
	sum1 += dist[n];
	sum2 += dist[u];

	if (min(sum1, sum2) >= 9999999) {
		cout << -1;
	}
	else {
		cout << min(sum1, sum2);
	}
}
