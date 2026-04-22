#include <iostream>
#include <vector>
#include <string.h>


using ll = long long;
using namespace std;

ll t;
ll v, e;
vector <ll> vc[200010];
ll visited[200010];
ll flag = 1;
void dfs(ll now, ll parent, ll chk) {
	for (auto i : vc[now]) {
		if (visited[i] != 0) {
			if (chk % 2 == 1) {
				if (visited[i] == 1) {
					flag = 0;
					return;
				}
			}
			else {
				if (visited[i] == 2) {
					flag = 0;
					return;
				}
			}
			continue;
		}
		else {
			if (chk % 2 == 1) {
				visited[i] = 2;
			}
			else {
				visited[i] = 1;
			}
		}
		dfs(i, now, chk + 1);
	}
}

void init() {
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
	memset(visited, 0, sizeof(visited));
	flag = 1;
		for (int i = 0; i < 200010; i++) {
			vc[i].clear();
		}
		cin >> v >> e;
		for (int i = 0; i < e; i++) {
			int start, end;
			cin >> start >> end;
			vc[start].push_back(end);
			vc[end].push_back(start);
		}
		for (int i = 1; i <= v; i++) {
			if (visited[i] == 0) {
				visited[i] = 2;
				dfs(i, -1, 0);
			}
		}
		if (flag == 0) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
		}
	}
}