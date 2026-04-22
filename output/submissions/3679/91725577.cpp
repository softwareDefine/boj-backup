#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define x first
#define y second

using ll = long long;
using namespace std;
using point = pair<ll, ll>;
map<point, ll> mp;


inline int ccw(point a, point b, point c) {
	ll dir = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);
	return (dir > 0) - (dir < 0);
}
inline ll dist(point a, point b) {
	return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);
}
ll t;
vector <point> pt;
vector <point> vc;

int main()
{
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		mp.clear();
		pt.clear();
		vc.clear();
		for (int i = 0; i < n; i++) { ll x, y; cin >> x >> y; pt.push_back({ x,y }); vc.push_back({ x,y }); }
		sort(pt.begin(), pt.end(), [&](auto a, auto b) {
			if (a.x == b.x) { return a.y > b.y; };
			return a.x < b.x;
		});
		sort(pt.begin() + 1, pt.end(), [&](auto a, auto b) {
			ll dir = ccw(pt[0], a, b);
			if (dir == 0) {
                if(pt[0].y > a.y){
				return dist(pt[0], a) > dist(pt[0], b);   
                }else{
				return dist(pt[0], a) < dist(pt[0], b);
                }
			}
			return dir > 0;
		});
		for (int i = 0; i < pt.size(); i++) {
			mp.insert({ pt[i],i });
		}
		for (int i = 0; i < vc.size(); i++) {
			cout << mp[vc[i]] << ' ';
		}
		cout << '\n';
	}
}