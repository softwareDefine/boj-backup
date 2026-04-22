#include <iostream>
#include <vector>
#include <set>
#include <map>

using ll = long long;
using namespace std;

vector<ll> vc[250010];
set<ll> st;
set<ll> st2;
ll n, q;
ll sum;
ll cnt[250010];
bool visited[250010];
ll use[250010];
ll treep[250010];
ll parent[250010];

int find(int now) {
	if (parent[now] == now) { return now; }
	return parent[now] = find(parent[now]);
}

void merge(int start, int end) {
	ll stp = find(start);
	ll edp = find(end);
	if (stp > edp) {
		parent[stp] = edp;
		cnt[edp] += cnt[stp];
	}
	else {
		parent[edp] = stp;
		cnt[stp] += cnt[edp];
	}
}

void dfs(ll now) {
	visited[now] = 1;
	for (auto& i : vc[now]) {
		if (!visited[i]) {
			merge(now, i);
			treep[i] = now;
			dfs(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i = 1; i <= 250006; i++) {
		parent[i] = i;
	}
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int start, end;
		cin >> start >> end;
		vc[start].push_back(end);
		vc[end].push_back(start);
	}
	dfs(1);
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int k;
		sum = 0;
		st2.clear();
		st.clear();
		cin >> k;
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			st.insert(a);
			cnt[a] = 1;
			parent[a] = a;
			use[a] = i;
		}
		for (auto& j : st) {
			if (use[j] == i && use[treep[j]] == i) {
				merge(j, treep[j]);
			}
		}
		for (auto& j : st) {
			st2.insert(find(j));
		}
		for (auto& j : st2) {
			sum += cnt[find(j)] * (cnt[find(j)] - 1) / 2;
		}
		cout << sum << '\n';
	}
}