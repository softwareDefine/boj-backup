#include <iostream>
#include <queue>

using namespace std;

long long f, s, g, u, d;
int visited[1000010];
void bfs() {
	queue<pair<int, int>> qu;
	qu.push({s,0});
	while (!qu.empty()) {
		int x = qu.front().first;
		int cnt = qu.front().second;
		qu.pop();
		if (x == g) {
			cout << cnt;
			return;
		}
		if ( x+u <= f && x+u > 0 && visited[x + u] != 1) {
			qu.push({ x + u,cnt + 1 });
			visited[x + u] = 1;
		}if( x -d > 0 && x-d <= f&& visited[x - d]!=1) {
			qu.push({ x - d,cnt + 1 });
			visited[x - d] = 1;
		}
	}
	cout << "use the stairs";
}

int main()
{
	cin >> f >> s >> g >> u >> d;
	if (s == g) {
		cout << 0;
		
	}
	else {

		bfs();
	}
}
