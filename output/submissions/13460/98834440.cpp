#include <bits/stdc++.h>

using namespace std;

typedef struct {
	int i;
	int j;
	char color;
} marble;

int n,m;
vector<marble> marbles;
vector<marble> hole;
string mp[20];
int mmn = 999999999;

void go(int now,int dir) {
	if(now >= 12 || hole.size() > 1 || (!hole.empty() && hole[0].color == 'B')) {
		return;
	}
	if(!hole.empty() && hole[0].color == 'R') {
		mmn = min(mmn,now-1);
		return;
	}
	if(dir == 0) {
		sort(marbles.begin(),marbles.end(),[](auto a,auto b) {
			return a.j < b.j;
		});
		for(int a=0; a<marbles.size(); a++) {
			int& i = marbles[a].i;
			int& j = marbles[a].j;
			char color = marbles[a].color;
			while(mp[i][j-1] != '#' && (a != marbles.size()-1 || i != marbles[a-1].i || j-1 != marbles[a-1].j)) {
				j--;
				if(mp[i][j] == 'O') {
					i = n-1;
					j = m-1;
					hole.push_back({i,j,color});
					break;
				}
			}
		}
	} else if(dir == 1) {
		sort(marbles.begin(),marbles.end(),[](auto a,auto b) {
			return a.i < b.i;
		});
		for(int a=0; a<marbles.size(); a++) {
			int& i = marbles[a].i;
			int& j = marbles[a].j;
			char color = marbles[a].color;
			while(mp[i-1][j] != '#' && (a != marbles.size()-1 || i-1 != marbles[a-1].i || j != marbles[a-1].j)) {
				i--;
				if(mp[i][j] == 'O') {
					i = n-1;
					j = m-1;
					hole.push_back({i,j,color});
					break;
				}
			}
		}
	} else if(dir == 2) {
		sort(marbles.begin(),marbles.end(),[](auto a,auto b) {
			return a.j > b.j;
		});
		for(int a=0; a<marbles.size(); a++) {
			int& i = marbles[a].i;
			int& j = marbles[a].j;
			char color = marbles[a].color;
			while(mp[i][j+1] != '#' && (a != marbles.size()-1 || i != marbles[a-1].i || j+1 != marbles[a-1].j)) {
				j++;
				if(mp[i][j] == 'O') {
					i = n-1;
					j = m-1;
					hole.push_back({i,j,color});
					break;
				}
			}
		}
		
	} else {
		sort(marbles.begin(),marbles.end(),[](auto a,auto b) {
			return a.i > b.i;
		});
		for(int a=0; a<marbles.size(); a++) {
			int& i = marbles[a].i;
			int& j = marbles[a].j;
			char color = marbles[a].color;
			while(mp[i+1][j] != '#' && (a != marbles.size()-1 || i+1 != marbles[a-1].i || j != marbles[a-1].j)) {
				i++;
				if(mp[i][j] == 'O') {
					i = n-1;
					j = m-1;
					hole.push_back({i,j,color});
					break;
				}
			}
		}
	}
	for(int i=0; i<4; i++) {
		if((i+2)%4 != dir) {
			auto before = marbles;
			auto behole = hole;
			go(now+1,i);
			marbles = before;
			hole = behole;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> mp[i];
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(mp[i][j] == 'R') {
				marbles.push_back({i,j,'R'});
				mp[i][j] = '.';
			} else if(mp[i][j] == 'B') {
				marbles.push_back({i,j,'B'});
				mp[i][j] = '.';
			}
		}
	}
	for(int i=0; i<4; i++) {
		auto before = marbles;
		auto behole = hole;
		go(1,i);
		marbles = before;
		hole = behole;
	}
	if(mmn == 999999999) {
		cout << -1;
	} else {
		cout << mmn;
	}
}