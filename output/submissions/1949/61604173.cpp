#include <iostream>
#include <vector>

using namespace std;

int cost[10010];
vector<int> vc[10010];
int dp[10010][2];
int visited[10010];
int use[10010];
int mmx1;
int n;

void dfs(int now) {
	int flag = 0;
	visited[now] = 1;
	for (auto& i : vc[now]) {
		if (!visited[i]) {
			dfs(i);
			dp[now][0] += max(dp[i][1],dp[i][0]);
			dp[now][1] += dp[i][0];
			if (!use[now]) {
				use[now] = 1;
				dp[now][1] += cost[now];
			}
			flag = 1;
		}
	}
	if (!flag) {
		dp[now][1] += cost[now];
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		vc[u].push_back(v);
		vc[v].push_back(u);
	}
	dfs(1);
	cout << max(dp[1][0], dp[1][1]);
}