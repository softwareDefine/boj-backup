#include <iostream>
#include <vector>

using ll = long long;
using namespace std;
vector<pair<ll, ll>> vc[100010];
ll visited[100010];
ll depth[100010];
ll parent[100010];
ll up[100010][110];
ll sumup[100010][110];

ll base;
ll sum[100010];
ll n;
ll q;

void dfs(ll now) {
	visited[now] = 1;
	for (auto& i : vc[now]) {
		if (!visited[i.first]) {
			visited[i.first] = 1;
			parent[i.first] = now;
			depth[i.first] = depth[now] + 1;
			sum[i.first] = i.second;
			dfs(i.first);
		}
	}
}

ll lca(ll u, ll v) {
	if (u == v) { return u; }
	if (depth[u] < depth[v]) {
		swap(u, v);
	}
	for (ll i = base; i >= 0; i--) {
		if (depth[up[u][i]] >= depth[v] && up[u][i]) {
			u = up[u][i];
		}
	}
	for (ll i = base; i >= 0; i--) {
		if (up[u][i] != up[v][i] && up[u][i] && up[v][i]) {
			u = up[u][i];
			v = up[v][i];
		}
	}
	u = parent[u];
	return u;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (base = 0; (1 << base) <= n; base++);
	for (int i = 0; i < n-1; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		vc[a].push_back({ b,c });
		vc[b].push_back({ a,c });
	}
	dfs(1);
	for (ll i = 1; i <= n;i++) {
		up[i][0] = parent[i];
		sumup[i][0] = sum[i];
	}
	for (ll j = 1; (1 << j) <= n; j++) {
		for (ll i = 1; i <= n; i++) {
			if (up[i][j-1]) {
				up[i][j] = up[up[i][j - 1]][j - 1];
				if (up[i][j]) {
					sumup[i][j] = sumup[up[i][j - 1]][j - 1] + sumup[i][j-1];
				}
			}
		}
	}
	cin >> q;
	for (int t = 0;t < q; t++) {
		ll a, b, c, d;
		cin >> a >> b >> c;
		ll cp = lca(b, c);
		if (a == 1) {
			ll ans = 0;
			for (int i = base; i >= 0; i--) {
				if (up[b][i] && depth[up[b][i]] >= depth[cp]) {
					ans += sumup[b][i];
					b = up[b][i];
				}
			}
			for (int i = base; i >= 0; i--) {
				if (up[c][i] && depth[up[c][i]] >= depth[cp]) {
					ans += sumup[c][i];
					c = up[c][i];
				}
			}
			cout << ans << '\n';
		}
		else {
			cin >> d;
			d -= 1;
			for (ll i = base; i >= 0; i--) {
				if (up[b][i] && depth[up[b][i]] >= depth[cp] && d - (1<<i) >=0) {
					d -= (1<<i);
					b = up[b][i];
				}
			}
			if (d == 0) {
				cout << b << '\n';
			}
			else {
				ll chk = 0;
				ll temp = c;
				for (ll i = base; i >= 0; i--) {
					if (up[temp][i] && depth[up[temp][i]] >= depth[cp]) {
						temp = up[temp][i];
						chk += (1 << i);
					}
				}
				chk = chk - d;
				for (ll i = base; i >= 0; i--) {
					if (up[c][i] && depth[up[c][i]] >= depth[cp] && chk - (1 << i) >= 0) {
						chk -= (1 << i);
						c = up[c][i];
					}
				}
				cout << c << '\n';
			}
		}
	}
}