#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int parent[1000010];
int visit[1000010];
queue<pair<int,int>> qu;
vector<pair<int, pair<int, int>>> vc;
vector<pair<int, int>> con[100010];
int n, m, k;

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
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	for (int i = 0; i <= 100000; i++) {
		parent[i] = i;
	}
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		vc.push_back({ cost,{start,end} });
	}
	sort(vc.begin(), vc.end(), [&](auto a, auto b) {
		return a.first > b.first;
	});
	for (auto &i : vc) {
		int start = i.second.first;
		int end = i.second.second;
		int cost = i.first;
		if (find(start) != find(end)) {
			merge(start, end); 
			con[start].push_back({ cost,end });
			con[end].push_back({ cost,start });
		}
	}
	int start, end;
	for (int i = 0; i < k; i++) {
		cin >> start >> end;
		qu.push({ start ,9999999 });
		while (!qu.empty()) {
			int now = qu.front().first;
			int cost = qu.front().second;
			qu.pop();
			if (now == end) {
				cout << cost << '\n';
				break;
			}
			for (auto& j : con[now]) {
				if (!visit[j.second]) {
					qu.push({ j.second ,min(j.first,cost) });
					visit[j.second] = 1;
				}
			}
		}
		while (!qu.empty()) {
			qu.pop();
		}
		fill(visit, visit + n + 1, 0);
	}
}