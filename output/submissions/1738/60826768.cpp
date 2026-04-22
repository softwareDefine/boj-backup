#include <iostream>
#include <vector>
#define inf -1000000010
using ll = long long;
using namespace std;

ll dist[110];
ll route[110];
ll chk[110];
ll wrong;
vector<ll> ans;
ll cnt;
vector<pair<int, ll>> vc[110];
int n, m;

int main()
{
	fill(dist, dist + 110, inf);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		vc[start].push_back({ end,cost });
	}
	dist[1] = 0;
	bool isChange = false;
	for (int i = 1; i <= 10000; i++) {
		for (int j = 1; j <= n; j++) {
			for (auto& k : vc[j]) {
				int e = k.first;
				int cost = k.second;
				if (dist[j]!= inf && dist[e] < dist[j] + cost) {
					dist[e] = dist[j] + cost;
					if (i < n) {
						route[e] = j;
					}
					if (i >= n) {
						chk[e] = 1;
					}
				}
			}
		}
	}
	int i = n;
	while (i != 1) {
		ans.push_back(i);
		if (chk[i] == 1) {
			wrong = 1;
			break;
		}
		i = route[i];
		if (ans.size() > 10000) {
			wrong = 1;
			break;
		}
	}
	ans.push_back(1);
	if (wrong) {
		cout << "-1";
	}
	else {
		for (int i = ans.size() - 1; i >= 0; i--) {
			cout << ans[i] << ' ';
		}
	}
}