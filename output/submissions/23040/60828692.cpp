#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

vector<int> vc[100010];
int szze[100010];
int parent[100010];
ll cnt;
string str;
int n;

int find(int now) {
	if (parent[now] == now) { return now; }
	return parent[now] = find(parent[now]);
}

void merge(int st, int ed) {
	int stp = find(st);
	int edp = find(ed);
	if (stp != edp) {
		parent[edp] = stp;
		szze[stp] += szze[edp];
	}
}

void dfs1(int now,int parent) {
	for (auto &k : vc[now]) {
		if (str[k - 1] == 'R' && parent != k) {
			merge(k, now);
		}
	}
}

void dfs2(int now, int parent) {
	for (auto& k : vc[now]) {
		if (str[k - 1] == 'R' && parent != k) {
			cnt += szze[find(k)];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr);cin >> n;
	for (int i = 1; i <= n; i++) { parent[i] = i; szze[i] = 1; }
	
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		vc[v].push_back(u);
		vc[u].push_back(v);
	}
	cin >> str;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'R') {
			dfs1(i+1,-1);
		}
	}
	for (int i = 0; i < n; i++) {
		if (str[i] == 'B') {
			dfs2(i + 1, -1);
		}
	}
	cout << cnt;
}