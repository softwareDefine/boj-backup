#define x first
#define y second
#include <bits/stdc++.h>

using namespace std;
using point = pair<int, int>;

typedef struct{
	point now;
	int dir;
	int rtat;
	int cnt;
}node;

point st, ed;

int t;

int xbound[2200][2200];
int ybound[2200][2200];
int filled[2200][2200];

pair<int,int> visited[110][110];

queue<node> qu;

int ans = 9999999;

int main() {
	cin >> st.x >> st.y;
	cin >> ed.x >> ed.y;
	cin >> t;
	for(int i = 0; i < 110; i++){
	    for(int j = 0; j < 110; j++){
	        visited[i][j] = {9999999,9999999};
	    }
	}
	while(t--) {
		point p[6];
		cin >> p[0].x >> p[0].y;
		cin >> p[1].x >> p[1].y;
		cin >> p[2].x >> p[2].y;
		cin >> p[4].x >> p[4].y;
		if(p[0].x == p[1].x) {
			p[3] = {p[2].x, p[4].y};
			p[5] = {p[4].x, p[0].y};
		    if(p[0].y > p[1].y){
		        for(int i = p[2].x; i < p[0].x; i++){
		            for(int j = p[0].y ; j < p[1].y; j++){
		                filled[i][j] = 1;
		            }
		        }
		        for(int i = p[4].x; i < p[2].x; i++){
		            for(int j = p[4].y ; j < p[0].y; j++){
		                filled[i][j] = 0;
		            }
		        }
		    }else{
		        for(int i = p[0].x; i < p[2].x; i++){
		            for(int j = p[1].y ; j < p[0].y; j++){
		                filled[i][j] = 1;
		            }
		        }
		        for(int i = p[2].x; i < p[4].x; i++){
		            for(int j = p[0].y ; j < p[4].y; j++){
		                filled[i][j] = 0;
		            }
		        }
		    }
		} else {
			p[3] = {p[4].x, p[2].y};
			p[5] = {p[0].x, p[4].y};
			if(p[0].x > p[1].x){
		        for(int i = p[1].x; i < p[0].x; i++){
		            for(int j = p[2].y ; j < p[1].y; j++){
		                filled[i][j] = 1;
		            }
		        }
		        for(int i = p[4].x; i < p[0].x; i++){
		            for(int j = p[2].y ; j < p[4].y; j++){
		                filled[i][j] = 0;
		            }
		        }
		    }else{
		        for(int i = p[0].x; i < p[1].x; i++){
		            for(int j = p[1].y ; j < p[2].y; j++){
		                filled[i][j] = 1;
		            }
		        }
		        for(int i = p[0].x; i < p[4].x; i++){
		            for(int j = p[4].y ; j < p[2].y; j++){
		                filled[i][j] = 0;
		            }
		        }
		    }
		}
		for(int a = 0; a < 6; a++) {
			auto now = p[a], next = p[(a+1)%6];
			if(now.x == next.x) {
				if(now.y > next.y) {
					for(int j = now.y-1; j >= next.y; j--) {
						ybound[now.x][j] = 1;
					}
				} else {
					for(int j = now.y; j < next.y; j++) {
						ybound[now.x][j] = 1;
					}
				}
			} else if(now.y == next.y) {
				if(now.x > next.x) {
					for(int i = now.x-1; i >= next.x; i--) {
						xbound[i][now.y] = 1;
					}
				} else {
					for(int i = now.x; i < next.x; i++) {
						xbound[i][now.y] = 1;
					}
				}
			}
		}
	}
	qu.push({st,1,0,0});
	qu.push({st,0,0,0});
	while(!qu.empty()) {
		auto [now, dir, rtat, cnt] = qu.front();
		if(now == ed) {
			ans = min(ans, rtat);
		}
		qu.pop();
		if(now.x+1 <= 100 && !(ybound[now.x][now.y] && !xbound[now.x][now.y])) {
			if( visited[now.x+1][now.y] > make_pair((dir?rtat+1:rtat),cnt+1) ) {
				visited[now.x+1][now.y] = { ( dir ? rtat + 1 : rtat), cnt + 1 };
				qu.push({{now.x+1,now.y}, 0, (dir?rtat+1:rtat), cnt+1});
			}
		}
		if(now.x-1 > 0 && !(ybound[now.x][now.y] && !xbound[now.x][now.y] && filled[now.x-1][now.y])) {
			if( visited[now.x-1][now.y] > make_pair((dir?rtat+1:rtat),cnt+1) ) {
				visited[now.x-1][now.y] = { ( dir ? rtat + 1 : rtat), cnt + 1 };
				qu.push({{now.x-1,now.y}, 0, (dir?rtat+1:rtat), cnt+1});
			}
		}
		if(now.y+1 <= 100 && !(!ybound[now.x][now.y] && xbound[now.x][now.y])) {
			if( visited[now.x][now.y+1] > make_pair((dir==0?rtat+1:rtat),cnt+1) ) {
				visited[now.x][now.y+1] = { ( dir==0 ? rtat + 1 : rtat), cnt + 1 };
				qu.push({{now.x,now.y+1}, 1, (dir==0?rtat+1:rtat), cnt+1});
			}
		}
		if(now.y-1 > 0 && !(!ybound[now.x][now.y] && xbound[now.x][now.y] && filled[now.x][now.y-1])) {
			if( visited[now.x][now.y-1] > make_pair((dir==0?rtat+1:rtat),cnt+1) ) {
				visited[now.x][now.y-1] = { ( dir==0 ? rtat + 1 : rtat), cnt + 1 };
				qu.push({{now.x,now.y-1}, 1, (dir==0?rtat+1:rtat), cnt+1});
			}
		}
	}
	cout << ans;
}