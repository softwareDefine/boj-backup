#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using ll = long long;
using namespace std;
vector <pair<int, pair<int, int >>> vc;
vector <pair<int, pair<int,pair<int, int >>>> newvc;
vector<int> chk;
set<int> st;
ll n, m;
ll mmn;
pair<int, ll> pr;

int parent[1000100];
int find(int now) {
	if (parent[now] == now) { return now; }
	return parent[now] = find(parent[now]);
}

void merge(int st, int ed) {
	int stp = find(st);
	int edp = find(ed);
	if (stp > edp) {
		parent[stp] = edp;
	}
	else {
		parent[edp] = stp;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		vc.push_back({ cost,{start,end} });
	}
	sort(vc.begin(), vc.end(), [&](auto a, auto  b) {
		return a.first < b.first;
	});
	for (int j = 1; j <= n; j++) { parent[j] = j; }
	for (int i = 0; i < m; i++) {
		if (find(vc[i].second.first) != find(vc[i].second.second)) {
			merge(vc[i].second.first, vc[i].second.second);
			newvc.push_back({ vc[i].first,{i,{vc[i].second.first,vc[i].second.second}}});
			mmn += vc[i].first;
		}
	}
	for (auto &i : newvc) {
		ll cost = 0;
		chk.clear();
		for (int j = 1; j <= n; j++) { parent[j] = j; }
		for (int j = 0; j < m; j++) {
			if (i.second.first == j) { continue; }
			if (find(vc[j].second.first) != find(vc[j].second.second)) {
				merge(vc[j].second.first, vc[j].second.second);
				cost += vc[j].first;
			}
		}
		for (int j = 1; j <= n; j++) {
			if (chk.empty()) {
				chk.push_back(find(parent[j]));
				continue;
			}
			if (chk[0] != find(parent[j])) {
				chk.push_back(parent[j]);
			}
		}
		if (chk.size() > 1 || cost > mmn) {
			pr.first++;
			pr.second += i.first;
		}
	}
	cout << pr.first << ' ' << pr.second << '\n';
}