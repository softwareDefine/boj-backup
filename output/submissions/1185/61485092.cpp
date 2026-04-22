#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using ll = long long;
using namespace std;
int parent[100100];
int ncost[100010];
vector<pair<ll,pair<int,int>>> vc;
int n,m;
ll sum;

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
		parent[edp] = stp;
	}
	else {
		parent[stp] = edp;
	}
}

int main()
{
	iota(parent, parent + 100010, 0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> ncost[i];
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		ll c;
		cin >> u >> v >> c;
		vc.push_back({ (2*c)+ncost[u]+ncost[v],{u,v}});
	}
	sort(vc.begin(), vc.end());
	for (auto& i : vc) {
		if (find(i.second.first) != find(i.second.second)) {
			merge(i.second.first, i.second.second);
			sum += i.first;
		}
	}
	cout << sum+*min_element(ncost+1,ncost+n);
}