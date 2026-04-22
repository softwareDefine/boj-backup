#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> vc[250010];
set<int> st;
map<int, int> mp;
int n,q;
long long sum;
bool visited[250010];
int parent[250010];

int find(int now) {
	if (parent[now] == now) { return now; }
	return parent[now] = find(parent[now]);
}

void merge(int start, int end) {
	int stp = find(start);
	int edp = find(end);
	if (stp > edp) {
		parent[stp] = edp;
	}
	else {
		parent[edp] = stp;
	}
}

void dfs(int now) {
	if (visited[now]) { return; }
	visited[now] = 1;
	for (auto& i : vc[now]) {
		if (st.find(i)!=st.end()) {
			merge(now, i);
			dfs(i);
		}
	}
}

int main()
{
	for (int i = 1; i <= 250006; i++) {
		parent[i] = i;
	}
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int start, end;
		cin >> start >> end;
		vc[start].push_back(end);
		vc[end].push_back(start);
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int k;
		sum = 0;
		mp.clear();
		st.clear();
		cin >> k;
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			st.insert(a);
		}
		for (auto& j : st) {
			dfs(j);
		}
		for (auto& j : st) {
			mp[find(j)]++;
		}
		for (auto& j : mp) {
			sum += j.second* (j.second - 1) / 2;
		}
		for (auto& j : st) {
			parent[j] = j;
			visited[j] = 0;
		}
		cout << sum << '\n';
	}
}