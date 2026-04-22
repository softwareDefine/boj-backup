#include <iostream>
#include <queue>

using namespace std;
int n, m, k;
string str[1010];
bool visited[1010][1010];
int s1, s2, e1, e2;

int bfs(int x1, int y1) {
	queue<pair<pair<int, int>, int>> qu;
	qu.push({ {x1,y1},0 });
	while (!qu.empty()) {
		int x = qu.front().first.first;
		int y = qu.front().first.second;
		int cnt = qu.front().second;
		//cout << x << ' ' << y << ' ' << cnt << '\n';
		if (x == e1 && e2 == y) {
			return cnt;
		}
		qu.pop();
		int a = 0, b = 0, c = 0, d = 0;
		for (int i = 1; i <= k; i++) {
			if (x + i < n && (str[x + i][y] == '#' || visited[x + i][y])) {
				a = 1;
			}
			if (x + i < n  && a != 1) {
				qu.push({ { x + i,y }, cnt + 1 });
				visited[x + i][y] = 1;
			}

			if (y + i < m && (str[x][y + i] == '#' || visited[x][y + i])) {
				b = 1;
			}
			if (y + i < m && b != 1) {
				qu.push({ {x,y + i},cnt + 1 });
				visited[x][y + i] = 1;
			}

			if (x - i >= 0 && (str[x - i][y] == '#' || visited[x - i][y])) {
				c = 1;
			}
			if (x - i >= 0 && c != 1) {
				qu.push({ {x - i,y},cnt + 1 });
				visited[x - i][y] = 1;
			}

			if (y - i >= 0 && (str[x][y - i] == '#' || visited[x][y - i])) {
				d = 1;
			}
			if (y - i >= 0 && d != 1) {
				qu.push({ {x,y - i},cnt + 1 });
				visited[x][y - i] = 1;
			}
		}
	}
	if (qu.empty()) {
		return -1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	cin >> s1 >> s2;
	cin >> e1 >> e2;
	s1 -= 1;
	s2 -= 1;
	e1 -= 1;
	e2 -= 1;
	cout << bfs(s1, s2);
}