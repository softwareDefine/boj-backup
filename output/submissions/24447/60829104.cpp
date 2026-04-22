#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;
long long n, m, r;
vector<long long> vc[10001000];
long long depth[10000100];
long long visited[10000100];
long long ans[10000010];
long long ptr = 1;
long long sum = 0;
void bfs(long long start) {
	queue<long long> qu;
	visited[start] = 1;
	depth[start] = 0;
	qu.push(start);
	ans[start] = ptr++;
	while (!qu.empty()) {
		long long now = qu.front();
		sort(vc[now].begin(), vc[now].end());
		qu.pop();
		for (auto i : vc[now]) {
			if (!visited[i]) {
				qu.push(i);
				depth[i] = depth[now] + 1;
				ans[i] = ptr++;
				visited[i] = 1;
			}
		}
	}
}

int main()
{
	cin >> n >> m >> r;
	fill(depth,depth+n+1,-1);
	for (int i = 0; i < m; i++) {
		long long u, v;
		cin >> u >> v;
		vc[u].push_back(v);
		vc[v].push_back(u);
	}
	bfs(r);
	for (int i = 1; i <= n; i++) {
		sum += ans[i] *depth[i];
	}
	cout << sum;
}