#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> vc[1000010];
int dp[1000010];
int on[1000010];

int dfs(int now) {
	dp[now] = 0;
	for (auto& i : vc[now]) {
		if (dp[i] == -1) {
			dp[now] += dfs(i);
			if ( !on[now] && !on[i]) {
				on[now] = 1;
				dp[now] += 1;
			}
		}
	}
	return dp[now];
}

int main()
{
	fill(dp, dp + 1000010, -1);
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		vc[u].push_back(v);
		vc[v].push_back(u);
	}
	cout << dfs(1);
}