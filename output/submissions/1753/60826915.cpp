#include <iostream>
#include <vector>
#include <queue>
#define inf 99999999

using namespace std;

int n, m,start;
vector<pair<int, int>> vertex[1000000];
int mdistance[1000000];

void digestar() {
	priority_queue<pair<int, int>> pq; // first거리 ,second목적지
	mdistance[start] = 0;
	pq.push({0,start});

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int current = pq.top().second;
		pq.pop();
		if (mdistance[current] < dist) {
			continue;
		}
		for (int i = 0; i < vertex[current].size(); i++) {
			int nc = vertex[current][i].second;
			int nd = dist + vertex[current][i].first;
			if (nd < mdistance[nc]) {
				mdistance[nc] = nd;
				pq.push({-nd,nc});
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	cin >> start;
	for (int i = 1; i <= n; i++) {
		mdistance[i] = inf;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vertex[a].push_back({ c,b });
		vertex[b].push_back({ c,b });
	}
	digestar();
	for (int i = 1; i <= n; i++) {
		if (mdistance[i] == inf) {
			cout << "INF" << '\n';
			continue;
		}
		cout << mdistance[i] << '\n';
	}
}

