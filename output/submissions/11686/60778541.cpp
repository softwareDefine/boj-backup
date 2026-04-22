#define x first
#define y second
#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;
using point = pair<long, long>;
vector<point> v;
vector<point> pt;
ll cnt = 0;
int ccw(point a, point b, point c) {
	ll res = a.x * b.y + b.x * c.y + c.x * a.y;
	res -= a.y * b.x + b.y * c.x + c.y * a.x;
	return (res > 0) - (res < 0);
}
inline ll dist(point a,point b) {
	return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}
void check(vector<point> &v, vector<point> &pt) {
	swap(v[0], *min_element(v.begin(), v.end()));
	sort(v.begin() + 1, v.end(), [&](auto a, auto b) {
		ll dir = ccw(v[0], a, b);
		if (dir != 0) {
			return dir > 0;
		}
		return dist(v[0], a) < dist(v[0], b);
	});
	vector<point> ans;
	for (auto i : v) {
		while (ans.size() >= 2 && ccw(ans[ans.size() - 2], ans.back(), i)<=0) {
			ans.pop_back();
		}
		ans.push_back(i);
	}
	for (auto j : pt) {
		if (ccw(ans[0], ans[1], j) < 0) continue;
		int l = 1, r = ans.size() - 1;
		while (l < r) {
			int m = l + r + 1 >> 1;
			if (ccw(ans[0], ans[m], j) >= 0) {
				l = m;
			}
			else {
				r = m - 1;
			}
		}
		if (l == ans.size() - 1) {
			if (ccw(ans[0], ans.back(), j) == 0 && ans[0] <= j && j <= ans.back()) {
				cnt++;
			}
		}else if (ccw(ans[0], ans[l], j) >= 0 && ccw(ans[l], ans[l + 1], j) >= 0 && ccw(ans[l + 1], ans[0], j) >= 0) {
			cnt++;
		}
	}
}

int main()
{
	int l, s;
	cin >> l;
	for (int i = 0; i < l; i++) {
		point a;
		cin >> a.x >> a.y;
		v.push_back(a);
	}
	cin >> s;
	for (int i = 0; i < s; i++) {
		point a;
		cin >> a.x >> a.y;
		pt.push_back(a);
	}
	check(v, pt);
	cout << cnt;
}