#include <bits/stdc++.h>

using namespace std;

int n;

string mp[100];

vector<pair<int,int>> starter;
vector<pair<int,int>> ender;

pair<pair<int,int>,int> B;
pair<pair<int,int>,int> E;

bool visited[100][100][2];

queue<pair<pair<pair<int,int>,int>,int>> qu;

bool bfs() {
	visited[B.first.first][B.first.second][B.second] = 1;
	qu.push({B,0});
	while(!qu.empty()) {
		int i = qu.front().first.first.first;
		int j = qu.front().first.first.second;
		int rotate = qu.front().first.second;
		int cnt = qu.front().second;
		if(E == qu.front().first) {
			cout << cnt;
			return 1;
		}
		qu.pop();
		if(rotate == 0) {
			//L
			if(j-2 >= 0 && mp[i][j-2] != '1' && !visited[i][j-1][rotate]) {
				visited[i][j-1][rotate] = 1;
				qu.push({{{i,j-1},rotate},cnt+1});
			}
			//R
			if(j+2 < n && mp[i][j+2] != '1' && !visited[i][j+1][rotate]) {
				visited[i][j+1][rotate] = 1;
				qu.push({{{i,j+1},rotate},cnt+1});
			}
			//U
			if(i-1 >= 0 && mp[i-1][j-1] != '1' && mp[i-1][j] != '1' && mp[i-1][j+1] != '1' && !visited[i-1][j][rotate]) {
				visited[i-1][j][rotate] = 1;
				qu.push({{{i-1,j},rotate},cnt+1});
			}
			//D
			if(i+1 < n && mp[i+1][j-1] != '1' && mp[i+1][j] != '1' && mp[i+1][j+1] != '1'  && !visited[i+1][j][rotate]) {
				visited[i+1][j][rotate] = 1;
				qu.push({{{i+1,j},rotate},cnt+1});
			}
			int flag = 0;
			if(i <= 0 || i >= n-1) {
				flag =1;
			} else {
				for(int a = -1; a<=1; a++) {
					for(int b=-1; b<=1; b++) {
						if(mp[i+a][j+b] == '1') {
							flag =1;
						}
					}
				}
			}
			if(!flag && !visited[i][j][(rotate+1)%2]) {
				visited[i][j][(rotate+1)%2] = 1;
				qu.push({{{i,j},(rotate+1)%2},cnt+1});
			}
		} else {
			//U
			if(i-2 >= 0 && mp[i-2][j] != '1' && !visited[i-1][j][rotate]) {
				visited[i-1][j][rotate] = 1;
				qu.push({{{i-1,j},rotate},cnt+1});
			}
			//D
			if(i+2 < n && mp[i+2][j] != '1' && !visited[i+1][j][rotate]) {
				visited[i+1][j][rotate] = 1;
				qu.push({{{i+1,j},rotate},cnt+1});
			}
			//L
			if(j-1 >= 0 && mp[i-1][j-1] != '1' && mp[i][j-1] != '1' && mp[i+1][j-1] != '1' && !visited[i][j-1][rotate]) {
				visited[i][j-1][rotate] = 1;
				qu.push({{{i,j-1},rotate},cnt+1});
			}
			//D
			if(j+1 < n && mp[i-1][j+1] != '1' && mp[i][j+1] != '1' && mp[i+1][j+1] != '1'  && !visited[i][j+1][rotate]) {
				visited[i][j+1][rotate] = 1;
				qu.push({{{i,j+1},rotate},cnt+1});
			}
			int flag = 0;
			if(j <= 0 || j >= n-1) {
				flag =1;
			} else {
				for(int a = -1; a<=1; a++) {
					for(int b=-1; b<=1; b++) {
						if(mp[i+a][j+b] == '1') {
							flag =1;
						}
					}
				}
			}
			if(!flag && !visited[i][j][(rotate+1)%2]) {
				visited[i][j][(rotate+1)%2] = 1;
				qu.push({{{i,j},(rotate+1)%2},cnt+1});
			}
		}
	}
	return 0;
}
	int main() {
	    cin.tie(0)->sync_with_stdio(0);
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> mp[i];
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(mp[i][j] == 'B') {
					starter.push_back({i,j});
					mp[i][j] = '0';
				}
				if(mp[i][j] == 'E') {
					ender.push_back({i,j});
					mp[i][j] = '0';
				}
			}
		}
		if(starter[0].first == starter[1].first) {
			B = {starter[1],0};
		} else {
			B = {starter[1],1};
		}
		if(ender[0].first == ender[1].first) {
			E = {ender[1],0};
		} else {
			E = {ender[1],1};
		}
		if(!(bfs())){
		    cout << 0;
		}
	}