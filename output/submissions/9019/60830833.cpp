#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int t;
int visited[10010];
pair<int, char> parent[10010];

void bfs(int a, int b) {
	queue<int> qu;
	qu.push(a);
	while (!qu.empty()) {
		int now = qu.front();
		qu.pop();
		if (now == b) {
			return;
		}
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				if (!visited[2 * now % 10000]) {
					qu.push({ 2 * now % 10000 });
					parent[2 * now % 10000] = { now,'D' };
					visited[2 * now % 10000] = 1;
				}
			}
			else if (i == 1) {
				if (!visited[(now == 0) ? 9999 : now - 1]) {
					qu.push({ (now == 0) ? 9999 : now - 1 });
					parent[(now == 0) ? 9999 : now - 1] = { now,'S' };
					visited[(now == 0) ? 9999 : now - 1] = 1;
				}
			}
			else if (i == 2) {
				int k = now % 1000 * 10 + now / 1000;
				if (!visited[k]) {
					qu.push({ k });
					parent[k] = { now,'L' };
					visited[k] = 1;
				}
			}
			else if (i == 3) {
				int k =  now / 10 + now % 10 * 1000;
				if (!visited[k]) {
					qu.push({ k });
					parent[k] = { now,'R' };
					visited[k] = 1;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		memset(parent, 0, sizeof(parent));
		memset(visited, 0, sizeof(visited));
		int start, end;
		cin >> start >> end;
		bfs(start, end);
		int now = end;
		vector<char> vc;
		while (now != start) {
			vc.push_back(parent[now].second);
			now = parent[now].first;
		}
		for (int i = vc.size() - 1; i >= 0; i--) {
			cout << vc[i];
		}
		cout << '\n';
	}
}