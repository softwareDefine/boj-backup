#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> vertex[1<<22];
int visited[1<<22];
int distment[1<<22];
int dist;
int mmx;
int mmxidx;
void dfs(int now) {
	visited[now] = 1;
	for (int i = 0; i < vertex[now].size();i++) {
		int  x = vertex[now][i].first;
		if (!visited[x]) {
			dist += vertex[now][i].second;
			distment[x] = dist;
			visited[x] = 1;
			dfs(x);
			dist -=vertex[now][i].second;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		while (1) {
			int b;
			cin >> b;
			if (b == -1) {
				break;
			}
			int c;
			cin >> c;
			vertex[a].push_back({b,c});
		}
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		if (mmx < distment[i]) {
			mmx = distment[i];
			mmxidx = i;
		}
	}
	for (int i = 0; i <= n; i++) {
		distment[i] = 0;
		visited[i] = 0;
	}
	dfs(mmxidx);
	mmx = 0;
	for (int i = 1; i <= n; i++) {
		mmx = max(mmx, distment[i]);
	}
	cout << mmx;
}