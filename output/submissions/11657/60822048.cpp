#include <iostream>
#define inf 1e8
#include <vector>
#include <algorithm>


using ll = long long;
using namespace std;

vector<pair<int, int>> vc[100010];
int n, m;
ll dist[100010];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vc[a].push_back({ b,c });
	}
	fill(dist, dist + 100010, inf);
	dist[1] = 0;
	bool isCircle = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (auto& k : vc[j]) {
				int e = k.first;
				ll cost = k.second;
				if (dist[j] != inf && dist[e] > dist[j] + cost) {
					dist[e] = dist[j] + cost;
					if (i == n) {
						isCircle = true;
					}
				}
			}
		}
	}
	if (isCircle == true) { cout << "-1"; return 0; }
	for (int i = 2; i <= n; i++) {
		if (dist[i] == inf) { cout << "-1" << '\n'; continue; }
		cout << dist[i] << '\n';
	}
}