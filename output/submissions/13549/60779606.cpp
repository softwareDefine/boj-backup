#include <iostream>
#include <queue>

using namespace std;
int mover[3] = { -1,1,2 };
int a, b;
int visit[100010];
int bfs(int now,int cnt) {
	deque<pair<int, int>> qu;
	qu.push_back({now,cnt});
	visit[now] = 1;
	while (!qu.empty()) {
		int cur = qu.front().first;
		int curc = qu.front().second;
		if (cur == b) {
			return curc;
		}
		qu.pop_front();
        if (cur * mover[2] <= 100000 && visit[cur*mover[2]]!=1) {
				qu.push_front({cur*mover[2],curc});
				visit[cur*mover[2]] = 1;
        }
		if (cur + mover[0] >= 0 && cur + mover[0] <= 100000 && visit[cur + mover[0]] != 1) {
					qu.push_back({ cur + mover[0],curc + 1 });
					visit[cur + mover[0]] = 1;
        }
        if (cur + mover[1] >= 0 && cur + mover[1] <= 100000 && visit[cur + mover[1]] != 1) {
					qu.push_back({ cur + mover[1],curc + 1 });
					visit[ cur + mover[1]] = 1;
        }
	}
}

int main()
{
	cin >> a >> b;
	cout << bfs(a, 0);
}
