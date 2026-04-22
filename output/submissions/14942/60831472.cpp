#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

ll arr[100010];
ll parent[100010];
ll up[100010][110];
ll sumup[100010][110];
ll sum[100010];
bool visited[100010];
int n;
vector<pair<int, ll>> vc[100010];

void dfs(int now) {
	visited[now] = 1;
	for (auto &i : vc[now]) {
		if (!visited[i.first]) {
			visited[i.first] = 1;
			sum[i.first] = i.second;
			parent[i.first] = now;
			dfs(i.first);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		vc[a].push_back({ b,c });
		vc[b].push_back({ a,c });
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		up[i][0] = parent[i];
		sumup[i][0] = sum[i];
	}
	for (int j = 0; (1<<j) <= n; j++) {
		for (int i = 1; i <= n; i++) {
			if (up[i][j - 1]) {
				up[i][j] = up[up[i][j - 1]][j - 1];
				if (up[i][j]) {
					sumup[i][j] = sumup[i][j - 1] + sumup[up[i][j - 1]][j - 1];
				}
			}
		}
	}
	int base = 0;
	for (base = 0; (1 << base) <= n; base++);
	for (int i = 1; i <= n; i++) {
		int now = i;
		ll cost = arr[now];
		for (int j = base; j >= 0; j--) {
			if (up[now][j] && cost - sumup[now][j] >= 0) {
				cost -= sumup[now][j];
				now = up[now][j];
			}
		}
		cout << now << '\n';
	}
}