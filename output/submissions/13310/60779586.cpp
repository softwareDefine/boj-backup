#define x first
#define y second
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
using ll = long long;
using point = pair < ll, ll >;

point zero = { 0,0 };

int n;
ll t;
ll res = 9223372036854775800;
vector<point> arr;
vector<point> v;

int ccw(point a, point b, point c) {
	ll res = a.x * b.y + b.x * c.y + c.x * a.y;
	res -= a.y * b.x + b.y * c.x + c.y * a.x;
	return (res > 0) - (res < 0);
}

vector<point> preprocessing(vector<point> vc,ll day) {
	for (ll i = 0; i < n; i++) {
		vc[i].x += v[i].x * day;
		vc[i].y += v[i].y * day;
	}
	return vc;
}

ll dist(point a, point b) {
	return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

point operator- (point a, point b) {
	return { b.x - a.x,b.y - a.y };
}

int chk(point a,point b,point c,point d) {
	point xx = b - a;
	point yy = d - c;
	return ccw(zero,xx,yy) >= 0;
}

ll convexhull(ll day) {
	vector<point> pt = preprocessing(arr, day);
	swap(pt[0],*min_element(pt.begin(),pt.end()));
	sort(pt.begin()+1, pt.end(), [&](auto a, auto b) {
		ll dir = ccw(pt[0], a, b);
		if (dir != 0) {
			return dir > 0;
		}
		return dist(pt[0], a) < dist(pt[0], b);
	});
	vector<point> ans;
	for (auto &i : pt) {
		while (ans.size() >= 2 && ccw(ans[ans.size()-2],ans.back(),i)<=0) {
			ans.pop_back();
		}
		ans.push_back(i);
	}
	ll j = 0;
	ll mmx = 0;
	point mmxx;
	point mmxy;
	for (ll i = 0; i < ans.size(); i++) {
		ll now;
		while (j + 1 < ans.size() && chk(ans[i],ans[i+1],ans[j],ans[j+1])) {
			now = dist(ans[i], ans[j]);
			if (now > mmx) {
				mmx = now;
				mmxx = ans[i];
				mmxy = ans[j];
			}
			j++;
		}
		now = dist(ans[i], ans[j]);
		if (now > mmx) {
			mmx = now;
			mmxx = ans[i];
			mmxy = ans[j];
		}
	}
	return mmx;
}
int main()
{
	cin >> n >> t;
	for (ll i = 0; i < n; i++) {
		ll ax, ay;
		ll dx, dy;
		cin >> ax >> ay >> dx >> dy;
		arr.push_back({ ax,ay });
		v.push_back({ dx,dy });
	}
	ll l = 0;
	ll r = t;
	while (r - l >= 3) {
		ll p = (l * 2 + r) / 3;
		ll q = (l + r * 2) / 3;
		if (convexhull(p) > convexhull(q)) {
			l = p;
		}
		else {
			r = q;
		}
	}
	ll time;
	for (ll i = l; i <= r; i++) {
		if (convexhull(i) < res) {
			res = convexhull(i);
			time = i;
		}
	}
	cout << time << '\n';
	cout << res;
}