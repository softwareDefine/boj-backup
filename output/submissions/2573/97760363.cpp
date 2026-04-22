#include <bits/stdc++.h>

using namespace std;

int n,m;
int mp[400][400];
int tmp[400][400];
int visited[400][400];

queue<pair<int,int>> qu;
int timer;
void go(int sx,int sy) {
    visited[sx][sy] = 1;
	qu.push({sx,sy});
	while(!qu.empty()) {
		int i = qu.front().first;
		int j = qu.front().second;
		//cout << i << ' ' << j << '\n';
		qu.pop();
		if(i+1 < n && (mp[i+1][j]) && !(visited[i+1][j])) {
			visited[i+1][j] = 1;
			qu.push({i+1,j});
		}
		if(i-1 >= 0 && (mp[i-1][j]) && !(visited[i-1][j])) {
			visited[i-1][j] = 1;
			qu.push({i-1,j});
		}
		if(j+1 < m && (mp[i][j+1]) && !(visited[i][j+1])) {
			visited[i][j+1] = 1;
			qu.push({i,j+1});
		}
		if(j-1 >= 0 && (mp[i][j-1]) && !(visited[i][j-1])) {
		    visited[i][j-1] = 1;
			qu.push({i,j-1});
		}
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> mp[i][j];
		}
	}
	while(1) {
	    timer++;
		int zerocount = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(mp[i][j]) {
					int cnt=0;
					if(i+1 < n && !mp[i+1][j]) {
						cnt++;
					}
					if(i-1 >= 0 && !mp[i-1][j]) {
						cnt++;
					}
					if(j+1 < m && !mp[i][j+1]) {
						cnt++;
					}
					if(j-1 >= 0 && !mp[i][j-1]) {
						cnt++;
					}
					tmp[i][j] = max(mp[i][j]-cnt,0);
				} else {
					zerocount++;
				}
			}
		}
		if(zerocount == n*m) {
			cout << 0;
			break;
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				mp[i][j] = tmp[i][j];
				//cout << tmp[i][j] << ' ';
			}
			//cout << '\n';
		}
		int contient = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(mp[i][j] && !visited[i][j]) {
					go(i,j);
					contient++;
				}
			}
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				visited[i][j] = 0;
			}
		}
		if(contient > 1) {
		    //cout << contient;
		    cout << timer;
            break;
		}
	}
}