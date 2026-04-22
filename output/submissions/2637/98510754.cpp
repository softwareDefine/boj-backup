#include <bits/stdc++.h>

using namespace std;

int n,m;

vector<pair<int,int>> vc[200];
int arr[200][200];
int in[200];

queue<int> qu;

int main() {
	cin >> n;
	cin >> m;
	for(int i=0; i<m; i++) {
		int u,v,c;
		cin >> u >> v >> c;
		vc[v].push_back({u,c});
		in[u]++;
	}
	for(int i=1; i<=n; i++) {
		if(!(in[i])) {
			arr[i][i] = 1;
			qu.push(i);
		}
	}
	while(!qu.empty()) {
		int now = qu.front();
		qu.pop();
		for(auto [next,cost] : vc[now]) {
			for(int i=1; i<=n; i++) {
				arr[next][i] += cost * arr[now][i];
			}
			in[next]--;
			if(!in[next]) {
				qu.push(next);
			}
		}
	}
	for(int i=1; i<=n; i++) {
		if(arr[n][i]) {
			cout << i << ' ' << arr[n][i] << '\n';
		}
	}
}