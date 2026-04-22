#include <iostream>

using namespace std;

int n, q;
int up[2000010];
int parent[2000010];
pair<int,pair<int,int>> query[10010];

int find(int now) {
	if (parent[now] == now) {
		return now;
	}
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

int main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		cin >> up[i];
	}
	q += n - 1;
	for (int i = q-1; i >= 0; i--) {
		cin >> query[i].first >> query[i].second.first;
		if (query[i].first == 1) {
			cin >> query[i].second.second;
		}
	}
	for (int i = 0; i < q; i++) {
		if (query[i].first == 0) {
			merge(query[i].second.first, up[query[i].second.first]);
		}
		else {
			cout << ((find(query[i].second.first) == find(query[i].second.second))?"YES":"NO") << '\n';
		}
	}
}