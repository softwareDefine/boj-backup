#include <iostream>
#include <queue>

using namespace std;
int mover[3] = { -1,1,2 };
vector<int> ans;
int a, b;
int visit[100010];
int cnt2;
int mcurc = 9999999;
void bfs(int now, int cnt) {
	queue<pair<int, int>> qu;
	qu.push({ now,cnt });
	visit[now] = 1;
	while (!qu.empty()) {
		int cur = qu.front().first;
		int curc = qu.front().second;
		qu.pop();
		visit[cur] = 1;
		if (mcurc < curc) {
			break;
		}
		if (cur == b) {
			mcurc = curc;
			cnt2++;
		}
		
		if (cur * mover[2] <= 100000 && visit[cur * mover[2]] != 1) {
			qu.push({ cur * mover[2],curc + 1 });
		}
		if (cur + mover[0] >= 0 && cur + mover[0] <= 100000 && visit[cur + mover[0]] != 1) {
			qu.push({ cur + mover[0],curc + 1 });
		}
		if (cur + mover[1] >= 0 && cur + mover[1] <= 100000 && visit[cur + mover[1]] != 1) {
			qu.push({ cur + mover[1],curc + 1 });
		}
	}
}

int main()
{
	cin >> a >> b;
	bfs(a,0);
	cout << mcurc << '\n';
	cout << cnt2;
}
