#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<pair<int, int>> vertex[40010];
int parent[40010];
int visited[40010];
int depth[40010];
int dist[40010];

int lca(int st,int ed) {
	if (depth[st] < depth[ed]) {
		swap(st, ed);
	}
	while (depth[st] != depth[ed]) {
		st = parent[st];
	}
	while (st != ed) {
		st = parent[st];
		ed = parent[ed];
	}
	return st;
}


void dfs(int st) {
	queue<int> qu;
	qu.push(st);
	depth[st] = 0;
	visited[st] = 1;
	parent[st] = 0;
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		for (auto y : vertex[x]) {
			if (visited[y.first] == 0) {
				visited[y.first] = 1;
				depth[y.first] = depth[x] + 1;
				parent[y.first] = x;
				dist[y.first] = dist[x] + y.second;
				qu.push(y.first);
			}
		}
	}
}

int main()
{
	int m;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int st, ed, val;
		cin >> st >> ed >> val;
		vertex[st].push_back({ ed, val });
		vertex[ed].push_back({ st,val });
	}
	dfs(1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int st, ed;
		cin >> st >> ed;
		cout <<dist[st]+dist[ed]-2*dist[lca(st, ed)] << '\n';
	}
}