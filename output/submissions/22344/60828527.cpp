#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

vector<pair<ll, ll>> vc[1000010];
vector<ll> chk;
ll node[1000010];
bool visited[1000010];
ll cntv[1000010];
ll n, m;
ll sum;
ll flag = 0;
ll x =0;
void dfs(ll now,ll cnt) {
	if (cnt %2== 1) {
		chk.push_back(node[now]);
	}
	else {
		chk.push_back(-node[now]);
	}
	cntv[now] = cnt;
	visited[now] = 1;
	for (auto &i : vc[now]) {
		ll next = i.first;
		ll cost = i.second;
		if (!visited[next]) {
			node[next] = cost - node[now];
			dfs(next,cnt+1);
		}
		else {
			if ( ((cntv[next]%2 == 0) && (cntv[now]%2==0))&&(cost - node[next] - node[now])%2==0 ) {
				if (!flag) {
					flag = 1;
					x = (cost - node[next] - node[now])/2;
				}
				else if (x != (cost - node[next] - node[now])/2 ) {
					cout << "NO";
					exit(0);
				}
			}
			else if (((cntv[next] % 2 == 1) && (cntv[now] % 2 == 1)) && (cost - node[next] - node[now]) % 2 == 0) {
				if (!flag) {
					flag = 1;
					x = -(cost - node[next] - node[now])/2;
				}
				else if (x != -(cost - node[next] - node[now])/2) {
					cout << "NO";
					exit(0);
				}
			}
			else if (((cntv[next] % 2 == 1 && cntv[now] %2 == 0) || (cntv[next] % 2 == 0 && cntv[now] % 2 == 1))) {
				if (node[next] + node[now] != cost) {
					cout << "NO";
					exit(0);
				}
			}
			else {
				cout << "NO";
				exit(0);
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (ll i = 0;i < m;i++) {
		ll start, end, cost;
		cin >> start >> end >> cost;
		vc[start].push_back({ end,cost });
		vc[end].push_back({ start,cost });
	}
	node[1] = 0;
	dfs(1,0);
	sort(chk.begin(), chk.end());
	cout << "Yes" << '\n';
	if (!flag) {
		for (ll i = 1;i <= n;i++) {
			if (cntv[i] % 2 == 0) {
				cout << node[i] + chk[n/2] << ' ';
			}
			else {
				cout << node[i] - chk[n/2] << ' ';
			}
		}
	}
	else {
		for (ll i = 1;i <= n;i++) {
			if (cntv[i] % 2 == 0) {
				cout << node[i] + x << ' ';
			}
			else {
				cout << node[i] - x << ' ';
			}
		}
	}
}