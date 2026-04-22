#include <iostream>
#include <vector>
#include<queue>

using namespace std;
int n;
vector<int> vertex[50010];
int parent[50010];
int depth[50010];
int visited[50010];
int lca(int st, int ed) {
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		vertex[u].push_back(v);
		vertex[v].push_back(u);
	}
	depth[1] = 0;
	visited[1] = true;
	queue<int> qu;
	qu.push(1);
	parent[1] = 0;
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		for (auto y : vertex[x]) {
			if (visited[y] != 1) {
				visited[y] = 1;
				depth[y] = depth[x] + 1;
				parent[y] = x;
				qu.push(y);
			}
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}
}