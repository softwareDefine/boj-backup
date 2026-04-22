#define x first
#define y second
#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;
using point = pair<ll, ll>;
vector<point> vc;
ll n;
int ccw(point a, point b, point c) {
	ll res = a.x * b.y + b.x * c.y + c.x * a.y;
	res -= a.y * b.x + b.y * c.x + c.y * a.x;
	return (res > 0) - (res < 0);
}

ll dist(point a, point b) {
	return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		point a;
		char c;
		cin >> a.x >> a.y >> c;
		if (c == 'Y') {
			vc.push_back(a);
		}
	}
    sort(vc.begin(),vc.end());
	swap(vc[0], *min_element(vc.begin(), vc.end()));
	sort(vc.begin() + 1, vc.end(), [&](auto a, auto b) {
		ll dir = ccw(vc[0], a, b);
		if (dir != 0) return dir > 0;
		return a.y > b.y;
	});
	vector<point> ans;
	for (auto i : vc) {
		while (ans.size() >= 2 && ccw(ans[ans.size() - 2], ans.back(), i) < 0) {
			ans.pop_back();
		}
		ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (auto i : ans) {
		cout << i.x << ' ' << i.y << '\n';
	}
}