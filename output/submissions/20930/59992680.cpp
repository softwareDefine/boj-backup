#define x first
#define y second
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>

using namespace std;
using point = pair<int, int>;
using line = pair<point, point>;
vector<pair<int, int>> corsx;
vector<pair<int, int>> corsy;
set<int> stx;
set<int> sty;
int n,q;
int parent[200010];

int find(int now) {
	if (parent[now] == now) {
		return now;
	}
	return parent[now] = find(parent[now]);
}

void merge(int start,int end){
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
	for (int i = 1; i < 200010; i++) {
		parent[i] = i;
	}
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		line l;
		cin >> l.first.x >> l.first.y >> l.second.x >> l.second.y;
		if (l.first.x > l.second.x) {
			swap(l.first, l.second);
		}
		corsx.push_back({ l.first.x,i+1});
		corsx.push_back({ l.second.x,-(i + 1) });
		if (l.first.y > l.second.y) {
			swap(l.first, l.second);
		}
		corsy.push_back({ l.first.y,i + 1 });
		corsy.push_back({ l.second.y,-(i + 1) });
	}
	sort(corsx.begin(), corsx.end(), [](auto a, auto b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first < b.first;
	});
	for (auto &i : corsx) {
		if (i.second > 0) {
			for (auto& j : stx) {
				merge(parent[i.second], parent[j]);
				break;
			}
			stx.insert(i.second);
		}
		else {
			stx.erase(-i.second);
		}
	}
	sort(corsy.begin(), corsy.end(), [](auto a, auto b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first < b.first;
	});	for (auto& i : corsy) {
		if (i.second > 0) {
			for (auto& j : sty) {
				merge(i.second, j);
				break;
			}
			sty.insert(i.second);
		}
		else {
			sty.erase(-i.second);
		}
	}
	for (int i = 0; i < q; i++) {
		int st, ed;
		cin >> st >> ed;
		if (find(st) == find(ed)) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
}