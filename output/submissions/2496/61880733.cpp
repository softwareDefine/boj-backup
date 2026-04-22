#include <iostream>
#include <vector>
#define x first
#define y second

using namespace std;
using ld = long double;
using point = pair<int, int>;
int mmx = 0;
int mmxx = 0;
int mmxy = 0;
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
			int ans = go(vc[i].x, vc[j].y);
			if (ans > mmx) {
				mmx = ans;
				mmxx = vc[i].x + k / 2;
				mmxy =vc[j].y + k / 2;
			}
		}
	}
	cout << (mmxx+mmxy)/2 << ' ' << (mmxx-mmxy)/2 << '\n';
	cout << mmx;
}