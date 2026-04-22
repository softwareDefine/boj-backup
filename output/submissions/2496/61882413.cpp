#include <iostream>
#include <vector>
#define x first
#define y second

using namespace std;
using ld = long double;
using point = pair<ld, ld>;
int mmx = 0;
ld mmxx = 0;
ld mmxy = 0;
int n, m, k, t;
vector<point> vc;

int go(ld q, ld w) {
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
	cin >> n >> m >> t >> k;
	for (int i = 0; i < t; i++) {
		point p1;
		cin >> p1.x >> p1.y;
		vc.push_back({ p1.x + p1.y,p1.x - p1.y });
	}
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			point chk1 = back({ vc[i].x ,vc[j].y });
			if (chk1.y + k/2 >= m) {
				chk1.y = m - k / 2;
			}
			point p = foward(chk1);
			int ans = go(p.x,p.y);
			if (ans > mmx) {
				mmx = ans;
				mmxx = p.x ;
				mmxy = p.y ;
			}
		}
	}
	cout << (mmxx+mmxy)/2 << ' ' << (mmxx-mmxy)/2 +k/2<< '\n';
	cout << mmx;
}