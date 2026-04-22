#define x first
#define y second
#define LLONG_MAX 9223372036854775807
#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;
using point = pair < ll, ll>;

ll mmn3;
ll n;
vector<point> vc;
point zero = { 0,0 };
point operator- (point a, point b) {
	return { b.x - a.x,b.y - a.y };
}
inline ll square(ll a) {
	return a * a;
}
inline int ccw(point a, point b, point c) {
	return (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y);
}
inline ll dist(point a, point b) {
	return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}
inline ll distM(point a, point b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}
struct comparey {
	bool operator ()(point a, point b) {
		return tie(a.y, a.x) < tie(b.y, b.x);
	}
};
inline bool chk(point a, point b, point c, point d) {
	point ab = b - a;
	point cd = d - c;
	return ccw(zero, ab, cd) >= 0;
}

ll convexhull(vector<point> &vc) {
	swap(vc[0], *min_element(vc.begin(), vc.end()));
	sort(vc.begin() + 1, vc.end(), [&](auto a, auto b) {
		int dir = ccw(vc[0], a, b);
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
	ll mmx = -LLONG_MAX;
	for (ll i = 0,j=0; i < ans.size(); i++) {
		while (j + 1 < ans.size() && chk(ans[i], ans[i + 1], ans[j], ans[j + 1])) {
			ll now = dist(ans[i], ans[j]);
			if (now > mmx) {
				mmx = now;
			}
			j++;
		}
		ll now = dist(ans[i], ans[j]);
		if (now > mmx) {
			mmx = now;
		}
	}
	return mmx;
}
ll DnC(ll l, ll r) {
	if (l == r) {
		return LLONG_MAX;
	}
	ll mid = (l + r) / 2;
	ll xm = vc[mid].x;
	ll mmn = min(DnC(l, mid), DnC(mid + 1, r));
	sort(vc.begin() + l, vc.begin() + r + 1, comparey());
	vector<point> p;
	for (int i = l; i <= r; i++) {
		if (square(vc[i].x - xm) < mmn) {
			p.push_back(vc[i]);
		}
	}
	for (int i = 1; i < p.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (square(p[i].y - p[j].y) < mmn) {
				if (mmn > dist(p[i], p[j])) {
					mmn = dist(p[i], p[j]);
				}
			}
			else {
				break;
			}
		}
	}
	return mmn;
}

ll DnC2(ll l, ll r) {
	if (l == r) {
		return LLONG_MAX;
	}
	ll mid = (l + r) / 2;
	ll xm = vc[mid].x;
	ll mmn = min(DnC2(l, mid), DnC2(mid+1,r));
	sort(vc.begin() + l, vc.begin() + 1 + r,comparey());
	vector<point> p;
	for (int i = l; i <=r; i++) {
		if (abs(vc[i].x-xm) < mmn) {
			p.push_back(vc[i]);
		}
	}
	for (int i = 0; i < p.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (abs(p[i].y - p[j].y) < mmn) {
				mmn = min(mmn,abs(p[i].y - p[j].y)+ abs(p[i].x - p[j].x));
			}
			else {
				break;
			}
		}
	}
	return mmn;
}

ll maxchebyshev() {
	ll x1 = LLONG_MAX, x2 = -LLONG_MAX, y1 = LLONG_MAX, y2 = -LLONG_MAX;
	for (int i = 0; i < n; i++) {
		x1 = min(x1, vc[i].x);
		y1 = min(y1, vc[i].y);
		x2 = max(x2, vc[i].x);
		y2 = max(y2, vc[i].y);
	}
	return max(x2 - x1, y2 - y1);
}

//나정휘 썜 코드 
void turn(bool flag) {
	for (int i = 0; i < n; i++) {
		ll f = vc[i].x;
		ll s = vc[i].y;
		vc[i] = { f + s,f - s };
		if (flag)
		{
			vc[i].x /= 2;
			vc[i].y /= 2;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		point a;
		cin >> a.x >> a.y;
		vc.push_back(a);
	}
	cout << convexhull(vc) << '\n';
	sort(vc.begin(), vc.end());
	cout << DnC(0, n - 1) << '\n';

	turn(false);
	cout << maxchebyshev() << '\n';
	turn(true);
	sort(vc.begin(), vc.end());
	cout << DnC2(0, n - 1) << '\n';
	cout << maxchebyshev() << '\n';
	turn(false);
	sort(vc.begin(), vc.end());
	cout << DnC2(0, n - 1)/2 << '\n';
	turn(true);
}