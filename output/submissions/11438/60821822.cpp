#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> vertex[100100];
int visited[100100];
int depth[100100];
int parent[100100];
int p[100100][110];
int n, m;

int lca(int st, int ed) {
	if (depth[st] < depth[ed]) {
		swap(st, ed);
	}
	int log = 1;
	for (log = 1; (1 << log) <= depth[st]; log++);
	log -= 1;
	for (int i = log; i >= 0; i--) {
		if (depth[st] - (1 << i) >= depth[ed]) {
			st = p[st][i];
		}
	}
	if (st == ed) {
		return st;
	}
	else {
		for (int i = log; i >= 0; i--) {
			if (p[st][i] != 0 && p[st][i] != p[ed][i]) {
				st = p[st][i];
				ed = p[ed][i];
			}
		}
		return parent[st];
	}
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
			if (visited[y] != 1) {
			depth[y] = depth[x] + 1;
			visited[y] = 1;
			parent[y] = x;
			qu.push(y);
			}
			
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int st, ed;
		cin >> st >> ed;
		vertex[st].push_back(ed);
		vertex[ed].push_back(st);
	}
	cin >> m;
	dfs(1);
	for (int i = 1; i <= n; i++) {
		p[i][0] = parent[i];
	}
	for (int j = 1; (1 << j) < n; j++) {
		for (int i = 1; i <= n; i++) {
			if (p[i][j - 1] != 0) {
				p[i][j] = p[p[i][j - 1]][j - 1];
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int st, ed;
		cin >> st >> ed;
		cout << lca(st, ed) << '\n';
	}
}