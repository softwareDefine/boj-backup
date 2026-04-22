#include <iostream>
#include <vector>
#include <iomanip>
#define x first
#define y second

using ld = long double;
using ll = long long;
using namespace std;
using point = pair<ll, ll>;
int mmx = 0;
ll mmxx = 0;
ll mmxy = 0;
int n, m, k, t;
vector<point> vc;

int go(ll q, ll w) {
	int ans = 0;
	for (auto& i : vc) {
		if (q <= i.x && i.x <= q + k && w <= i.y && i.y <= w+k) {
			ans++;
		}
	}
	return ans;
}
point back(point a) {
	return { (a.x + a.y) / 2,(a.x - a.y) / 2 };
}
point foward(point a) {
	return { (a.x + a.y),(a.x - a.y)};
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> t >> k;
	for (int i = 0; i < t; i++) {
		point p1;
		cin >> p1.x >> p1.y;
		vc.push_back({ p1.x + p1.y,p1.x - p1.y });
	}
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			point chk1 = back({ vc[i].x ,vc[j].y });
			point p = foward(chk1);
			int ans = go(p.x,p.y);
			if (ans > mmx) {
				mmx = ans;
				mmxx = p.x+k/2;
				mmxy = p.y+k/2;
			}
		}
	}
	cout << ((mmxx+mmxy)/2) << ' ' << ((mmxx-mmxy)/2) << '\n';
	cout << mmx;
}