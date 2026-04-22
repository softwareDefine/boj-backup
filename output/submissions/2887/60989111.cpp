#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using ll = long long;
using namespace std;
vector<pair<ll,int>> corsx;
vector<pair<ll, int>> corsy;
vector<pair<ll, int>> corsz;
priority_queue<pair<ll, pair<int, int>>> qu;
int n, parent[1000010];
ll sum;

inline void sorter(vector <pair<ll, int>> &k) {
	sort(k.begin(), k.end(), [&](auto a, auto b) {return a < b; });
}

inline void calc(vector <pair<ll, int>>& k) {
	for(int i=0;i<k.size()-1;i++){ 
		qu.push({ k[i + 1].first- k[i].first,{k[i].second,k[i+1].second}});
	}
}

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
	iota(parent, parent + 100010, 0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		corsx.push_back({ x,i });
		corsy.push_back({ y,i });
		corsz.push_back({ z,i });
	}
	sorter(corsx);
	sorter(corsy);
	sorter(corsz);
	calc(corsx);
	calc(corsy);
	calc(corsz);
	for (int i = 0; i < n - 1; i++) {
		ll cost = qu.top().first;
		int st = qu.top().second.first, ed = qu.top().second.second;
		if (find(st) != find(ed)) {
			merge(st, ed);
			sum += cost;
		}
	}
	cout << sum;
}