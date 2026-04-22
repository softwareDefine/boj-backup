#include <bits/stdc++.h>

using namespace std;

string mp[200];
string mykey;

int t;
int h,w;

typedef struct node {
	int i;
	int j;
	int cnt;
} node;

int visited[200][200];
queue<node> qu;

queue<node> waiting[200];
bool key[200];
int ans;

bool isDoor(int i,int j) {
	return (mp[i][j] >= 'A' && mp[i][j] <= 'Z');
}

bool isKey(int i,int j) {
	return (mp[i][j] >= 'a' && mp[i][j] <= 'z');
}

void move(int i,int j,int cnt) {
	if(mp[i][j] == '.') {
		qu.push({i,j,cnt});
	} else if(isKey(i,j)) {
		if(!(key[mp[i][j]-'a'])) {
			key[mp[i][j]-'a'] = 1;
			qu.push({i,j,cnt});
			while(!(waiting[mp[i][j]-'a'].empty())) {
				auto tmp = waiting[mp[i][j]-'a'].front();
				waiting[mp[i][j]-'a'].pop();
				qu.push(tmp);
			}
		}
	} else if(isDoor(i,j)) {
		if(key[mp[i][j]-'A']) {
			qu.push({i,j,cnt});
		} else {
			waiting[mp[i][j]-'A'].push({i,j,cnt});
		}
	} else if(mp[i][j] == '$') {
	    mp[i][j] = '.';
		qu.push({i,j,cnt});
		ans++;
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	while(t--) {
		cin >> h >> w;
		while(!qu.empty()) {
			qu.pop();
		}
		ans = 0;
		for(int i=0; i<200; i++) {
		    key[i] = 0;
			while(!waiting[i].empty()) {
				waiting[i].pop();
			}
			for(int j=0; j<200; j++) {
				visited[i][j] = 999999999;
			}
		}
		for(int i=0; i<h; i++) {
			cin >> mp[i];
		}
		cin >> mykey;
		if(mykey != "0") {
			for(int i=0; i<mykey.size(); i++) {
				key[mykey[i]-'a'] = 1;
			}
		}
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				if(i==0 || i==h-1 || j==0 || j==w-1) {
				    visited[i][j] = 0;
					move(i,j,0);
				}
			}
		}
		while(!qu.empty()) {
			auto [i,j,cnt] = qu.front();
			qu.pop();
			if(i-1 >=0 && mp[i-1][j] != '*' && visited[i-1][j] > cnt+1) {
				visited[i-1][j] = cnt+1;
				move(i-1,j,cnt+1);
			}
			if(i+1 < h && mp[i+1][j] != '*' && visited[i+1][j] > cnt+1) {
				visited[i+1][j] = cnt+1;
				move(i+1,j,cnt+1);
			}
			if(j-1 >= 0 && mp[i][j-1] != '*' && visited[i][j-1] > cnt+1) {
				visited[i][j-1] = cnt+1;
				move(i,j-1,cnt+1);
			}
			if(j+1 < w && mp[i][j+1] != '*' && visited[i][j+1] > cnt+1) {
				visited[i][j+1] = cnt+1;
				move(i,j+1,cnt+1);
			}
		}
		cout << ans << '\n';
	}
}