#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

char arr[1010][1010];
int w, h;
int flag = 0;
int mmn = 9999999;
queue<pair<pair<int,int>,int>> qu;
queue<pair<pair<int, int>,int>> fire;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		while (!qu.empty()) {
			qu.pop();
		}
		while(!fire.empty()) {
			fire.pop();
		}
		mmn = 9999999;
		flag = 0;
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == '*') {
					fire.push({ { i,j } ,0 });
				}
				else if (arr[i][j] == '@') {
					arr[i][j] = '.';
					qu.push({ {i,j},0 });
				}
			}
		}
		while (!qu.empty()) {
			int szze = fire.size();
			while(szze--) {
				int y = fire.front().first.first;
				int x = fire.front().first.second;
				int cnt = fire.front().second;
				fire.pop();
				for (int j = 0; j < 4; j++) {
					if (y + dy[j] >= 0 && y + dy[j] < h && x + dx[j] < w && x + dx[j] >= 0 && arr[y + dy[j]][x + dx[j]] != '#' &&  arr[y+dy[j]][x+dx[j]] != '*') {
						arr[y + dy[j]][x + dx[j]] = '*';
						fire.push({ {y + dy[j],x + dx[j]},cnt + 1 });
					}
				}
			}
			szze = qu.size();
			while(szze--) {
				int y = qu.front().first.first;
				int x = qu.front().first.second;
				int cnt = qu.front().second;
				qu.pop();
				if ((y == 0 || y == h - 1 || x == 0 || x == w - 1) && flag != 1) {
					flag = 1;
					mmn = cnt;
					break;
				}
				for (int j = 0; j < 4; j++) {
					if (y + dy[j] >= 0 && y + dy[j] < h && x + dx[j] < w && x + dx[j] >= 0 && arr[y + dy[j]][x + dx[j]] != '#' && arr[y + dy[j]][x + dx[j]] != '*' && arr[y+dy[j]][x+dx[j]]!='1') {
						arr[y + dy[j]][x + dx[j]] = '1';
						qu.push({ { y + dy[j],x + dx[j]} ,cnt + 1 });
					}
				}
			}
			
		}
		if (flag == 1) {
			cout << mmn + 1 << '\n';
		}
		else {
			cout << "IMPOSSIBLE" << '\n';
		}
	}
	
}