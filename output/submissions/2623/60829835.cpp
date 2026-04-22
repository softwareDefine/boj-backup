#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;
vector<int> vertex[1000000];
int connected[1000000];
vector<int> ans;
int flag;

void topologySort() {
	queue<int> qu;
	for (int i = 1; i <= n; i++) {
		if (connected[i] == 0) {
			qu.push(i);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (qu.empty()) {
			cout << "0";
			flag = 1;
			return;
		}
	int x = qu.front();
	ans.push_back(x);
	qu.pop();
		for (int j = 0; j < vertex[x].size(); j++) {
			if (--connected[vertex[x][j]] == 0) {
				qu.push(vertex[x][j]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, arr[1000];
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> arr[j];
		}
		for (int j = 1; j < a; j++) {
			vertex[arr[j-1]].push_back(arr[j]);
			connected[arr[j]]++;
		}
	}
	topologySort();
	if (flag != 1) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << '\n';
		}
	}
}
