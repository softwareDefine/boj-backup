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
				int temp = go(b.x - k, a.y);
				if (mmx < temp && b.x-k >= 1 && a.y-k>=1) {
					mmx = temp;
					mmxx =b.x-k;
					mmxy = a.y;
				}
				temp = go( b.x,a.y );
				if (mmx < temp && b.x - k >= 1 && a.y - k >=1) {
					mmx = temp;
					mmxx = a.x - k;
					mmxy = b.y;
				}

			}
			else {
				int temp = go(a.x, b.y);
				if (mmx < temp && a.x+k <= n && a.y-k>=0) {
					mmx = temp;
					mmxx = a.x;
					mmxy = b.y;
				}
				temp = go(b.x - k, a.y + k);
				if (mmx < temp && b.x - k >= 1 && a.y +k <= m) {
					mmx = temp;
					mmxx = b.x - k;
					mmxy = a.y - k;
				}
			}
		}
	}
	cout << mmxx << ' ' << mmxy << '\n';
	cout << mmx;
}