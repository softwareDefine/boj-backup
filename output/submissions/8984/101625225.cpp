#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n, l;
vector<pair<lint,lint>> stick;

unordered_map<lint, lint> dpDown;

lint ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> l;
	stick.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> stick[i].first >> stick[i].second;
	}
	sort(stick.begin(), stick.end(), [&](auto a, auto b) {
	    if(a.first == b.first){ return a.second < b.second; }
	    return a.first < b.first;
	});
	for(int i = 0; i < n; ){
	    int j = i;
	    while(j < n && stick[j].first == stick[i].first){ j++; }
	    unordered_map<lint, lint> pendingDown;
	    pendingDown.reserve((j-i)*2);
	    lint topMmx = 0;
	    for(int t = i; t < j; t++){
	        // 아래에서 붙이기
	        pendingDown[stick[t].second] = max(pendingDown[stick[t].second], topMmx + l + abs(stick[t].first - stick[t].second));
	        if(dpDown.find(stick[t].second) != dpDown.end()){
	            topMmx = max(topMmx, dpDown[stick[t].second] + l + abs(stick[t].first - stick[t].second));
	        }else{
	            topMmx = max(topMmx, l + abs(stick[t].first - stick[t].second));
	        }
	        ans = max(ans , max(pendingDown[stick[t].second], topMmx));
	    }
	    for(auto [a, b] : pendingDown){
	        dpDown[a] = b;
	    }
	    i = j;
	}
	cout << ans;
}