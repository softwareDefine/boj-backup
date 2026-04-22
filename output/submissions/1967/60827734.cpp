#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int n;
ll mmxidx;
ll mmx;
vector<pair<int,int>> arr[100010];

void dfs(int now,int parent,int depth,int var) {
	if (mmx < var) {
		mmx = var;
		mmxidx = now;
	}
	for (auto &i : arr[now]) {
		if (i.first == parent) {
			continue;
		}
		dfs(i.first, now, depth + 1, var + i.second);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int s, e, var;
		cin >> s >> e >> var;
		arr[s].push_back({ e,var });
		arr[e].push_back({ s,var });
	}
	dfs(1,-1,1,0);
	dfs(mmxidx, -1, 1, 0);
	cout << mmx;
}