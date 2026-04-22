#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;
int connected[100000];
priority_queue<int,vector<int>,greater<int>> vertex[100000];
int n, m;

void topologySort() {
	priority_queue<int, vector<int>, greater<int>> qu;
	for (int i = 1; i <= n; i++) {
		if (connected[i] == 0) {
			qu.push(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (qu.empty()) {
			cout << "-1"; 
			return;
		}
		int nx = qu.top();
		qu.pop();
		cout << nx << " ";
		int szze = vertex[nx].size();
		for (int j = 0; j < szze; j++) {
			int y = vertex[nx].top();
			vertex[nx].pop();
			if (--connected[y] == 0) {
				qu.push(y);
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vertex[a].push({b });
		connected[b]++;
	}
	topologySort();
}
