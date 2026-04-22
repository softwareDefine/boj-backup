#include <bits/stdc++.h>
 
using ld = long double;
using ll = long long;
using namespace std;

int n,k;
pair<ll,ll> point[2000];
queue<pair<ll,pair<ld,ll>>> qu;
pair<ld,ll> visited[2000];
ld dist(pair<ll,ll> a, pair<ll,ll> b) {
	return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}
bool bfs(ll fuel) {
    while(!qu.empty()){
        qu.pop();
    }
    for(int i=0;i<=n+1;i++){
        visited[i] = {0,0};
    }
    qu.push({0,{fuel*10,k}});
    while(!qu.empty()){
        ll now = qu.front().first;
        ld left = qu.front().second.first;
        ll airport = qu.front().second.second;
        qu.pop();
        if(now == n+1){
            return 1;
        }
        for(int i=0;i<=n+1;i++){
            ld nextleft = left - dist(point[now],point[i]);
            ll nextairport = airport;
            if(nextleft < 0){
                nextairport -=1;
                nextleft = fuel*10 - dist(point[now],point[i]);
                if(nextairport < 0 || nextleft < 0){
                    continue;
                }
            }
            if(visited[i].second < nextairport || (visited[i].second == nextairport && visited[i].first < nextleft)){
                visited[i].second = nextairport;
                visited[i].first = nextleft;
                qu.push({i,{nextleft,nextairport}});    
            }
        }
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for(int i=1; i<=n; i++) {
		cin >> point[i].first >> point[i].second;
	}
	point[n+1] = {10000,10000};
	ll left = 1;
	ll right = 1500;
	ll mid = 0;
	int counter = 0;
	while(left < right) {
	    if(mid == (left+right+1)/2){
		    counter++;
		    if(counter > 5){
		        break;
		    }
		}
		mid = (left+right+1)/2;
		//cout << left << ' ' << right  <<' '<< mid << ' ' << bfs(mid) << '\n';
		if(bfs(mid)) {
			right = mid;
		}else{
			left = mid;
		}
	}
	cout << mid;
}