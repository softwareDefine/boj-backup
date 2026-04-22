#include<bits/stdc++.h>

using namespace std;
using point = pair<int, int>;
using line = pair<point, point>;

int n, m;
int s, st;
vector<point> polygon;
vector<int> boundery;
vector<int> part;
int mmx;

int main() {
	cin >> n >> m;
	cin >> s;
	polygon.resize(s);
	for(auto &[x, y] : polygon) {
		cin >> x >> y;
	}
	for(int i = 0; i < s; i++) {
		auto [x,y] = polygon[i]; auto [nx, ny] = polygon[(i+1)%s];
		if( (x == 0 && nx == 0) || (x == n && nx == n) ||  (y == 0 && ny == 0) || (y == m && ny == m) ) {
		    st = i;
		    break;
        }
	}
	int tmp = 0;
	for(int i = st; i < st+s+1; i++) {
		auto [x,y] = polygon[i%s]; auto [nx, ny] = polygon[(i+1)%s];
		if( (x == 0 && nx == 0) || (x == n && nx == n) ||  (y == 0 && ny == 0) || (y == m && ny == m) ){
		    if(!boundery.empty() && boundery[boundery.size()-1] != (i-1+s)%s){
		        auto [bx, by] = polygon[boundery[boundery.size()-1]+1];
		        int cnt = 0;
		        while(bx != x || by != y){
		            if( bx == 0 && by != 0){
		                by -= 1;
		            }else if( by == 0 && bx != n){
		                bx += 1;
		            }else if( bx == n && by != m){
		                by += 1;
		            }else if( by == m ){
		                bx -= 1;
		            }
		            cnt++;
		        }
		        part.push_back(tmp + cnt);
		        tmp = 0;
		    }
            boundery.push_back(i%s);
        }else{
            tmp += abs(nx - x) + abs(ny - y);
        }
	}
	if(tmp && part.size() == 0){
	    cout << 1 << ' ' << tmp + 2*m + 2*n - (abs(polygon[st].first - polygon[(st+1)%s].first) + abs(polygon[st].second - polygon[(st+1)%s].second));
	}else{
	    cout << part.size() << ' ';
    	for(auto e : part){
    	    mmx = max(mmx, e);
    	}
    	cout << mmx;
	}
}