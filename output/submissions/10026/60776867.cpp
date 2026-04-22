#include <iostream>
#include <queue>

using namespace std;
int n;
char maper[110][110];
char redmaper[110][110];
int visited[110][110];
int redvisited[110][110];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

typedef struct h {
	int x;
	int y;
}j;


void mapdfs(int tx,int ty,char color) {
	queue<j> qu;
	qu.push({ tx,ty});
	visited[tx][ty] = 1;
	while (!qu.empty()) {
		int x = qu.front().x;
		int y = qu.front().y;
		qu.pop();
		for (int i = 0; i < 4; i++) {
			if (x+dx[i] >=0 && x+dx[i] <n && y+dy[i] >=0 && y+dy[i] <n && visited[x+dx[i]][y+dy[i]]!=1 && color == maper[x + dx[i]][y + dy[i]]){
				qu.push({ x+dx[i],y+dy[i]});
				visited[x + dx[i]][y + dy[i]] = 1;
			}
		}
	}
}
void reddfs(int rx, int ry,char rcolor) {
	queue<j> qu;
	qu.push({ rx,ry });
	visited[rx][ry] = 1;
	while (!qu.empty()) {
		int x = qu.front().x;
		int y = qu.front().y;
		qu.pop();
		for (int i = 0; i < 4; i++) {
			if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n && redvisited[x + dx[i]][y + dy[i]] != 1 && rcolor == redmaper[x + dx[i]][y + dy[i]]) {
				qu.push({ x + dx[i],y + dy[i] });
				redvisited[x + dx[i]][y + dy[i]] = 1;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maper[i][j];
			if (maper[i][j] == 'R' || maper[i][j] == 'G') {
				redmaper[i][j] = 'R';
			}
			else {
				redmaper[i][j] = maper[i][j];
			}
		}
	}
	int cnt=0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <n; j++) {
				if (visited[i][j] == 0) {
					mapdfs(i, j,maper[i][j]);
					cnt++;
				}
			}
		}
		int cnt2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (redvisited[i][j] == 0) {
					reddfs(i, j, redmaper[i][j]);
					cnt2++;
				}
			}
		}
		cout << cnt << " " << cnt2;
}