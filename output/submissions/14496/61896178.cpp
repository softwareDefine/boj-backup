#include <iostream>
#include <queue>

using namespace std;

int s, e;
int n, m;
int visited[100010];
vector<int> vc[100010];
int flag;
queue<pair<int,int>> qu;

int main()
{
	cin >> s >> e;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vc[a].push_back(b);
		vc[b].push_back(a);
	}
	qu.push({ s,0 });
	while (!qu.empty()) {
		int now = qu.front().first;
		int cnt = qu.front().second;
		qu.pop();
		if (now == e) {
			cout << cnt;
			flag = 1;
			break;
		}
		for (auto& i : vc[now]) {
			if (!visited[i]) {
				qu.push({ i,cnt+1});
			}
		}
	}
	if (!flag) {
		cout << -1;
	}
}