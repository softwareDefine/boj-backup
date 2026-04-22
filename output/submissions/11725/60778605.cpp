#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visited[1<<22];
int depth[1<<22];
int parent[1<<22];
vector<int> a[1<<22];
int n;

void bfs() {
	queue<int> q;
	depth[1] = 0;
	visited[1] = true;
	parent[1] = 0;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : a[x]) {
			if (!visited[y]) {
				depth[y] = depth[x] + 1;
				visited[y] = true;
				parent[y] = x;
				q.push(y);
			}
		}
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back({ y });
		a[y].push_back({ x });
	}
	bfs();
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
}