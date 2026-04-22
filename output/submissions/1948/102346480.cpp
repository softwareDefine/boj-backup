#include <bits/stdc++.h>

using lint = long long;
using namespace std;

typedef struct{
    lint now;
    lint route;
    lint tweight;
}Node;

lint n, m;

vector<pair<lint, lint>> edge[11000];
lint in[11000];
lint visited[11000];
pair<lint, lint> distMmx[11000];
lint h, r;

queue<Node> qu;
queue<lint> revQu[11000];
queue<lint> chk;

lint cnt;

int main() {
	cin >> n;
	cin >> m;
	for(int i = 0; i < m; i++){
	    lint u, v, w;
	    cin >> u >> v >> w;
	    edge[u].push_back({v, w});
	    in[v]++;
	}
	cin >> h >> r;
	qu.push({h, 1, 0});
	while(!qu.empty()){
	    auto [now, route, tweight] = qu.front();
	    qu.pop();
	    for(auto [next, nweight] : edge[now]){
	        if( distMmx[next].first < (tweight + nweight)){
	            distMmx[next] = make_pair(tweight + nweight, route);
	            while(!revQu[next].empty()){
	                revQu[next].pop();
	            }
	            revQu[next].push(now);
	        }else if(distMmx[next].first == (tweight + nweight)){
	            distMmx[next].second += route;
	            revQu[next].push(now);
	        }
	        if(!(--in[next])){ qu.push({next,  distMmx[next].second,  distMmx[next].first}); }
	    }
	}
	cout << distMmx[r].first << '\n';
	chk.push(r);
	while(!chk.empty()){
	    lint now = chk.front();
	    chk.pop();
	    if(visited[now]){ continue; }
	    visited[now] = 1;
	    while(!revQu[now].empty()){
	        chk.push(revQu[now].front());
	        revQu[now].pop();
	        cnt++;
	    }
	}
	cout << cnt;
	return 0;
}