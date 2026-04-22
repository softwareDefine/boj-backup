#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

struct line {
	ll a, b;
	double s;
	line() {
		line(1, 0);
	}
	line(ll a1, ll b1) {
		a = a1;
		b = b1;
		s = 0;
	}
};

ll n, arr[100010], brr[100010];
vector<line> vc;
ll dp[100010];

inline double cross(line& f, line& g) {
	return (g.b - f.b) / (f.a - g.a);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> brr[i];
	}
	for (int i = 1; i < n; i++) {
		line g(brr[i - 1], dp[i - 1]);
		while (vc.size()> 0) {
			g.s = cross(vc[vc.size()-1],g);
			if (vc[vc.size() - 1].s < g.s) {
				break;
			}
			vc.pop_back();
		}
		vc.push_back(g);

		ll x = arr[i];
		ll fpos = vc.size() - 1;
		if (x < vc.back().s) {
			int lo = 0; int hi = vc.size() - 1;
			while (lo + 1 < hi) {
				int mid = (lo + hi) / 2;
				(x < vc[mid].s ? hi : lo) = mid;
			}
			fpos = lo;
		}
		dp[i] = x * vc[fpos].a + vc[fpos].b;
	}
	cout << dp[n - 1];
}