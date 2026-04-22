#include <iostream>
#include <vector>
#define x first
#define y second

using namespace std;
using point = pair<int, int>;
int mmx = 0;
int mmxx = 0;
int mmxy = 0;
int n, m, k, t;
vector<point> vc;

int go(int q, int w) {
	int ans = 0;
	for (auto& i : vc) {
		if (q <= i.x && i.x <= q + k && w <= i.y && i.y <= w + k) {
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
		vc.push_back(p1);
	}
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			point a = vc[i], b = vc[j];
			point chk;
			if (a > b) swap(a, b);
			if (a.y > b.y) {
				chk = { b.x-k , a.y };
				if (mmx < go(b.x - k, a.y) && b.x-k >= 1) {
					mmx = go(b.x - k, a.y);
					mmxx =b.x-k;
					mmxy = a.y;
				}
			}
			else {
				int temp = go(a.x, b.y);
				if (mmx < go(a.x, b.y)) {
					mmx = go(a.x, b.y);
					mmxx = a.x;
					mmxy = b.y;
				}
			}
		}
	}
	cout << mmxx << ' ' << mmxy << '\n';
	cout << mmx;
}