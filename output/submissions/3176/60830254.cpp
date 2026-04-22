#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int parent[100010];
int dist[100010];
bool check[100010];
int depth[100010];
int p[100100][100];
int min_dis[100010][100];
int max_dis[100010][100];
int n,m;
vector<pair<int, int>> vc[100010];

pair<int, int> lca(int start, int end) {
	if (depth[start] < depth[end]) {
		swap(start, end);
	}
	int base = 1;
	int mmx = 0;
	int mmn = 100000010;
	for (base = 1; (1 << base) <= n; base++);
	base -= 1;
	for (int i = base; i >= 0; i--) {
		if (depth[start] - (1 << i) >= depth[end]) {
			mmx = max(mmx, max_dis[start][i]);
			mmn = min(mmn, min_dis[start][i]);
			start = p[start][i];
		}
	}
	if (start == end) {
		return { mmn,mmx };
	}
	else {
		for (int i = base; i >= 0; i--) {
			if (p[start][i] != 0 && p[start][i] != p[end][i]) {
				mmn = min(min_dis[start][i], mmn);
				mmn = min(min_dis[end][i], mmn);
				mmx = max(max_dis[start][i], mmx);
				mmx = max(max_dis[end][i], mmx);
				start = p[start][i];
				end = p[end][i];
			}
		}
		mmn = min(dist[start], mmn);
		mmn = min(dist[end], mmn);
		mmx = max(max_dis[start][0], mmx);
		mmx = max(max_dis[end][0], mmx);
		return { mmn,mmx };
	}
} 

void bfs() {
	queue<int> qu;
	qu.push(1);
	//parent[1] = -1;
	depth[1] = 1;
	check[1] = true;
	//dist[1] = 0;
	while (!qu.empty()) {
		int now = qu.front();
		qu.pop();
		for (auto& i : vc[now]) {
			int next = i.first;
			int cost = i.second;
			if (!check[next]) {
				dist[next] = cost;
				parent[next] = now;
				check[next] = true;
				depth[next] = depth[now] + 1;
				qu.push(next);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		vc[start].push_back({ end,cost });
		vc[end].push_back({ start,cost });
	}
	bfs();
	for (int i = 1; i <= n; i++) {
		p[i][0] = parent[i];
		min_dis[i][0] = dist[i];
		max_dis[i][0] = dist[i];
	}
	for (int j = 1; (1 << j) < n; j++) {
		for (int i = 1; i <= n; i++) {
			if (p[i][j - 1]!=0) {
				p[i][j] = p[p[i][j - 1]][j - 1];
				min_dis[i][j] = min_dis[i][j - 1];
				max_dis[i][j] = max_dis[i][j - 1];
				if (p[i][j] != 0) {
					min_dis[i][j] = min(min_dis[p[i][j - 1]][j - 1], min_dis[i][j - 1]);
					max_dis[i][j] = max(max_dis[p[i][j - 1]][j - 1], max_dis[i][j - 1]);
				}
			}
		}
	}
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int st, ed;
		cin >> st >> ed;
		pair<int, int> ans = lca(st, ed);
		cout << ans.first << ' ' << ans.second << '\n';
	}
}
