#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define inf 100000010

using ll = long long;
using namespace std;

int n, m;
ll sum = 0;
int parent[1000010];
vector<pair<pair<int,int>,int>> vc;

int find(int now) {
	if (parent[now] == now) {
		return now;
	}
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
	for (int i = 1; i < 1000010; i++) {
		parent[i] = i;
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		vc.push_back({ {start,end }, cost});
	}
	for (int i = 1; i <= n; i++) {
		int cost;
		cin >> cost;
		vc.push_back({ {i,0},cost });
	}
	sort(vc.begin(), vc.end(), [&](auto a, auto b) {return a.second < b.second; });
	for (auto &k : vc) {
		if (find(k.first.first) != find(k.first.second)) {
			merge(k.first.first, k.first.second);
			sum += k.second;
		}
	}
	cout << sum;
}