#include <bits/stdc++.h>

using namespace std;

int m,n;
int mp[200][200];
int visited[200][200][10];

int sx,sy,sd;
int ex,ey,ed;

typedef struct mapper {
	int x;
	int y;
	int dir;
	int cnt;
} mapper;

deque<mapper> dq;
int mmn = 99999999;
//int cnt;

int main() {
	for(int i=1; i<=100; i++) {
		for(int j=1; j<=100; j++) {
			for(int z=1; z<=4; z++) {
				visited[i][j][z] = 99999999;
			}
		}
	}
	cin >> m >> n;
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			cin >> mp[i][j];
		}
	}
	cin >> sx >> sy >> sd;
	cin >> ex >> ey >> ed;
	dq.push_back({sx,sy,sd,0});
	while(!dq.empty()) {
		int nowx = dq.front().x;
		int nowy = dq.front().y;
		int nowd = dq.front().dir;
		int cnt = dq.front().cnt;
		dq.pop_front();
		if(nowx == ex && nowy == ey && nowd == ed) {
			mmn = min(mmn,cnt);
		}
		switch(nowd) {
		case 1:
			if(nowy+1 <= n && !mp[nowx][nowy+1] && visited[nowx][nowy+1][nowd] > cnt+1) {
				visited[nowx][nowy+1][nowd] = cnt+1;
				dq.push_back({nowx,nowy+1,nowd,cnt+1});
			}
			if(nowy+2 <= n && !mp[nowx][nowy+1] && !mp[nowx][nowy+2] && visited[nowx][nowy+2][nowd] > cnt+1) {
				visited[nowx][nowy+2][nowd] = cnt+1;
				dq.push_front({nowx,nowy+2,nowd,cnt+1});
			}
			if(nowy+3 <= n && !mp[nowx][nowy+1] && !mp[nowx][nowy+2] && !mp[nowx][nowy+3] && visited[nowx][nowy+3][nowd] > cnt+1) {
				visited[nowx][nowy+3][nowd] = cnt+1;
				dq.push_front({nowx,nowy+3,nowd,cnt+1});
			}
			if(visited[nowx][nowy][3] > cnt+1) {
				visited[nowx][nowy][3] = cnt+1;
				dq.push_back({nowx,nowy,3,cnt+1});
			}
			if(visited[nowx][nowy][4] > cnt+1) {
				visited[nowx][nowy][4] = cnt+1;
				dq.push_back({nowx,nowy,4,cnt+1});
			}
			break;
		case 2:
			if(nowy-1 > 0 && !mp[nowx][nowy-1] && visited[nowx][nowy-1][nowd] > cnt+1) {
				visited[nowx][nowy-1][nowd] = cnt+1;
				dq.push_back({nowx,nowy-1,nowd,cnt+1});
			}
			if(nowy-2 > 0 && !mp[nowx][nowy-1] && !mp[nowx][nowy-2] && visited[nowx][nowy-2][nowd] > cnt+1) {
				visited[nowx][nowy-2][nowd] = cnt+1;
				dq.push_front({nowx,nowy-2,nowd,cnt+1});
			}
			if(nowy-3 > 0 && !mp[nowx][nowy-1] && !mp[nowx][nowy-2] && !mp[nowx][nowy-3] && visited[nowx][nowy-3][nowd] > cnt+1) {
				visited[nowx][nowy-3][nowd] = cnt+1;
				dq.push_front({nowx,nowy-3,nowd,cnt+1});
			}
			if(visited[nowx][nowy][3] > cnt+1) {
				visited[nowx][nowy][3] = cnt+1;
				dq.push_back({nowx,nowy,3,cnt+1});
			}
			if(visited[nowx][nowy][4] > cnt+1) {
				visited[nowx][nowy][4] = cnt+1;
				dq.push_back({nowx,nowy,4,cnt+1});
			}
			break;
		case 4:
			if(nowx-1 > 0 && !mp[nowx-1][nowy] && visited[nowx-1][nowy][nowd] > cnt+1) {
				visited[nowx-1][nowy][nowd] = cnt+1;
				dq.push_back({nowx-1,nowy,nowd,cnt+1});
			}
			if(nowx-2 > 0 && !mp[nowx-1][nowy] && !mp[nowx-2][nowy] && visited[nowx-2][nowy][nowd] > cnt+1) {
				visited[nowx-2][nowy][nowd] = cnt+1;
				dq.push_front({nowx-2,nowy,nowd,cnt+1});
			}
			if(nowx-3 > 0 && !mp[nowx-1][nowy] && !mp[nowx-2][nowy]  && !mp[nowx-3][nowy] && visited[nowx-3][nowy][nowd] > cnt+1) {
				visited[nowx-3][nowy][nowd] = cnt+1;
				dq.push_front({nowx-3,nowy,nowd,cnt+1});
			}
			if(visited[nowx][nowy][1] > cnt+1) {
				visited[nowx][nowy][1] = cnt+1;
				dq.push_back({nowx,nowy,1,cnt+1});
			}
			if(visited[nowx][nowy][2] > cnt+1) {
				visited[nowx][nowy][2] = cnt+1;
				dq.push_back({nowx,nowy,2,cnt+1});
			}
			break;
		case 3:
			if(nowx+1 <= m && !mp[nowx+1][nowy] && visited[nowx+1][nowy][nowd] > cnt+1) {
				visited[nowx+1][nowy][nowd] = cnt+1;
				dq.push_back({nowx+1,nowy,nowd,cnt+1});
			}
			if(nowx+2 <= m && !mp[nowx+1][nowy] && !mp[nowx+2][nowy] && visited[nowx+2][nowy][nowd] > cnt+1) {
				visited[nowx+2][nowy][nowd] = cnt+1;
				dq.push_front({nowx+2,nowy,nowd,cnt+1});
			}
			if(nowx+3 <= m && !mp[nowx+1][nowy] && !mp[nowx+2][nowy] && !mp[nowx+3][nowy] && visited[nowx+3][nowy][nowd] > cnt+1) {
				visited[nowx+3][nowy][nowd] = cnt+1;
				dq.push_front({nowx+3,nowy,nowd,cnt+1});
			}
			if(visited[nowx][nowy][1] > cnt+1) {
				visited[nowx][nowy][1] = cnt+1;
				dq.push_back({nowx,nowy,1,cnt+1});
			}
			if(visited[nowx][nowy][2] > cnt+1) {
				visited[nowx][nowy][2] = cnt+1;
				dq.push_back({nowx,nowy,2,cnt+1});
			}
			break;
		}
	}
	cout << mmn;
}