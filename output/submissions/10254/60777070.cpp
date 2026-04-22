#define x first
#define y second
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using point = pair<ll, ll>;


point zero = { 0,0 };
point mmxx;
point mmxy;
ll t;

int ccw(point a,point b,point c) {
	ll res = a.x * b.y + b.x * c.y + c.x * a.y;
	res -= a.y * b.x + b.y * c.x + c.y * a.x;
	return (res > 0) - (res < 0);
}

ll dist(point a, point b) {
	return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

point operator- (point a, point b) {
	return { b.x - a.x,b.y - a.y };
}

bool chk(point a, point b, point c,point d) {
	point t = b - a;
	point tt = d - c;
	return ccw(zero, t, tt) >= 0;
}

void convexhull(vector<point> &vc){
	swap(vc[0], *min_element(vc.begin(),vc.end()));
	sort(vc.begin()+1, vc.end(), [&](auto a, auto b) {
		ll dir = ccw(vc[0], a, b);
		if (dir != 0) {
			return dir > 0;
		}
		return dist(vc[0], a) < dist(vc[0], b);
	});
	vector<point> ans;
	for (auto i : vc) {
		while (ans.size() >= 2 && ccw(ans[ans.size() - 2], ans.back(), i) <= 0) {
			ans.pop_back();
		}
		ans.push_back(i);
	}
	ll ret = 0;
	ll pt = 0;
	for (int i = 0; i < ans.size(); i++) {
		ll now ;
		while (pt + 1 < ans.size() && chk(ans[i], ans[i + 1], ans[pt], ans[pt + 1])) {
			now = dist(ans[i], ans[pt]);
			if (now > ret) {
				ret = now;
				mmxx = ans[i];
				mmxy = ans[pt];
			}
			pt++;
		}
		now = dist(ans[i], ans[pt]);
		if (now > ret) {
			ret = now;
			mmxx = ans[i];
			mmxy = ans[pt];
		}
	}
}

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		vector<point> vc;
		ll n;
		cin >> n;
		for (ll j = 0; j < n; j++) {
			ll a, b;
			cin >> a >> b;
			vc.push_back({ a,b });
		}
		convexhull(vc);
		cout << mmxx.x << ' ' << mmxx.y << ' ';
		cout << mmxy.x << ' ' << mmxy.y << ' ' << '\n';
	}
}