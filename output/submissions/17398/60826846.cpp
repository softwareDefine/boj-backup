#include <iostream>
#include <vector>

using ll = long long;
using namespace std;
ll parent[1000010];
ll unable[1000010];
vector<ll> query;
vector<pair<ll, ll>> vc;
ll n, m, q;
ll ans;
ll szze[1000010];

int find(int now) {
	if (parent[now] == now) {return now;}
	return parent[now] = find(parent[now]);
}

void merge(int st, int ed) {
	int stp = find(st);
	int edp = find(ed);
	if (szze[stp] > szze[edp]) {
		parent[edp] = stp;
		szze[stp] += szze[edp];
	}
	else {
		parent[stp] = edp;
		szze[edp] += szze[stp];
	}
}

int main()
{
	for (int i = 0; i <= 1000000; i++) {
		parent[i] = i;
		szze[i] = 1;
	}
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vc.push_back({ a,b });
	}
	for (int i = 0; i < q; i++) {
		int a;
		cin >> a;
		unable[a] = 1;
		query.push_back(a);
	}
	for (int i = 0; i < m; i++) {
		if (unable[i + 1] == 1) {
			continue;
		}
		if (find(vc[i].first) != find(vc[i].second)) {
			merge(find(vc[i].first), find(vc[i].second));
		}
	}
	for (int i = q - 1; i >= 0; i--) {
		if (find(vc[query[i] - 1].first) != find(vc[query[i] - 1].second)) {
			ans += szze[find(vc[query[i] - 1].first)]* szze[find(vc[query[i] - 1].second)];
			merge(find(vc[query[i] - 1].first), find(vc[query[i] - 1].second));
		}
	}
	cout << ans;
}