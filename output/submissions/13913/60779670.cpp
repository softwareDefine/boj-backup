#include <iostream>
#include <queue>

using namespace std;
int mover[3] = { -1,1,2 };
vector<int> ans;
int parent[400010];
int a, b;
int visit[100010];
int bfs(int now, int cnt) {
	queue<pair<int, int>> qu;
	qu.push({ now,cnt });
	visit[now] = 1;
	while (!qu.empty()) {
		int cur = qu.front().first;
		int curc = qu.front().second;
		if (cur == b) {
			return curc;
		}
		qu.pop();
		if (cur * mover[2] <= 100000 && visit[cur * mover[2]] != 1) {
			qu.push({ cur * mover[2],curc+1});
			parent[cur * mover[2]] = cur;
			visit[cur * mover[2]] = 1;
		}
		if (cur + mover[0] >= 0 && cur + mover[0] <= 100000 && visit[cur + mover[0]] != 1) {
			qu.push({ cur + mover[0],curc + 1 });
			parent[cur + mover[0]] = cur;
			visit[cur + mover[0]] = 1;
		}
		if (cur + mover[1] >= 0 && cur + mover[1] <= 100000 && visit[cur + mover[1]] != 1) {
			qu.push({ cur + mover[1],curc + 1 });
			parent[cur + mover[1]] = cur;
			visit[cur + mover[1]] = 1;
		}
	}
}

int main()
{
	cin >> a >> b;
	for (int i = 0; i < 400010; i++) parent[i] = -1;
	int ed = bfs(a, 0);
	cout << ed <<'\n';
	while (b != -1) {
		ans.push_back(b);
		b = parent[b];
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
}
