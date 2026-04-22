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
		if (q <= i.x && i.x <= q + k && w-k <= i.y && i.y <= w) {
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
			if (a > b) swap(a, b);
			if (a.y > b.y) {
				int xx = b.x - k;
				int yy = a.y;
				if (xx <= 0) xx = 0;
				if (yy - k <= 0) yy = k;
				int temp = go(xx, yy);
				if (mmx < temp) {
					mmx = temp;
					mmxx =xx;
					mmxy = yy;
				}
				xx = a.x;
				yy = b.y + k;
				if (xx+k >= n) xx = n-k;
				if (yy >= m) yy = m-k;
				temp = go( xx,yy );
				if (mmx < temp ) {
					mmx = temp;
					mmxx = xx;
					mmxy = yy;
				}

			}
			else {
				int xx = b.x - k;
				int yy = a.y + k;
				if (xx <= 0) xx = 0;
				if (yy >= m) yy = m - k;
				int temp = go(xx, yy);
				if (mmx < temp ) {
					mmx = temp;
					mmxx = xx;
					mmxy = yy;
				}
				xx = a.x;
				yy = b.y;
				if (xx + k >= n) xx = n - k;
				if (yy - k <= 0) yy = 0;
				temp = go(a.x, b.y);
				if (mmx < temp) {
					mmx = temp;
					mmxx = xx;
					mmxy = yy;
				}
			}
		}
	}
	cout << mmxx << ' ' << mmxy << '\n';
	cout << mmx;
}