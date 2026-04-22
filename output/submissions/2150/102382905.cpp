#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint v, e;
vector<lint> edge[11000];

int visited[11000];
int unable[11000];
int parent[11000];

vector<lint> route;
map<int, vector<int>> mp;



int find(int now){
    if(parent[now] == now){
        return now;
    }
    return parent[now] = find(parent[now]);
}


void dfs(int now) {
	for(auto next : edge[now]) {
		if(!visited[next]) {
			route.push_back(next);
			visited[next] = 1;
			unable[next] = 1;
			dfs(next);
			visited[next] = 0;
			route.pop_back();
		} else {
			vector<lint> tmp;
			for(int j = route.size()-1 ; j >=0 && route[j] != next; j--) {
				tmp.push_back(route[j]);
			}
			tmp.push_back(next);
			sort(tmp.begin(), tmp.end());
    	    for(int i = 0; i < tmp.size()-1; i++){
    	        int parentU = find(tmp[i]), parentV = find(tmp[i+1]);
    	        if(parentU < parentV){ swap(parentU, parentV); }
    	        parent[parentU] = parentV;
    	    }
		}
	}
}

int main() {
    iota(parent,parent+11000,0);
	cin >> v >> e;
	for(int i = 0; i < e; i++) {
		lint a, b;
		cin >> a >> b;
		edge[a].push_back(b);
	}
	for(int i = 1; i <= v; i++) {
		if(!unable[i]) {
			visited[i] = 1;
			unable[i] = 1;
			route.push_back(i);
			dfs(i);
			while(!route.empty()) {
				route.pop_back();
			}
		}
	}
	for(int i = 1; i <= v; i++){
	    mp[find(i)].push_back(i);
	}
	cout << mp.size() << '\n';
	for(auto [hd, vc] : mp){
	    for(auto element : vc){
	        cout << element << ' ';
	    }
	    cout << -1 << '\n';
	}
	return 0;
}