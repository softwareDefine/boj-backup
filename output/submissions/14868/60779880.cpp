#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdio>
#define INF 987654321
#define P pair<int,int>

using namespace std;

int N, K;
int map[2001][2001];
int connect[100001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<P> city;
queue<P> q;

int Find(int x){
	if(connect[x] == x) return x;
	else return connect[x] = Find(connect[x]);
}

void Union(int x, int y){
	int X = Find(x);
	int Y = Find(y);
	if(X != Y){
		connect[X] = Y; 
	}
}

void merge_city(){
	while(	!city.empty()){
		int x = city.front().first;
		int y = city.front().second;
		q.push({x, y});
		city.pop();
		for(int i = 0; i < 4; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			int now_civil = map[x][y];
			int next_civil = map[xx][yy];
			if(xx >= 1 && xx <= N && yy >= 1 && yy <= N){
				if(map[xx][yy] != 0){
					if(now_civil != next_civil && Find(now_civil) != Find(next_civil)){
						Union(now_civil, next_civil);
						K--; 
					}	
				}
			}
		}
	}
}

void bfs(){
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx >= 1 && xx <= N && yy >= 1 && yy <= N){
				if(map[xx][yy] == 0){
					map[xx][yy] = map[x][y];
					city.push({xx,yy});
				}
			}
		}
	}
}

void solve(){
	int time_ = 0;
	while(K > 1){
		merge_city();
		if(K == 1){
			cout << time_;
			break;
		}
		bfs();
		time_++;
	}
}

int main(){
	cin >> N >> K;
	for(int i = 0; i < K; i++){
		int x, y;
		cin >> x >> y;
		map[x][y] = i+1;
		city.push({x,y});
	}
	for(int i = 1; i <= K; i++) connect[i] = i;
	solve();
	return 0;
}