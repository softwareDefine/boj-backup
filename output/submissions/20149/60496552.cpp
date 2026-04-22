#include <iostream>
#include <cmath>
#define x first
#define y second

using ll = long long;
using namespace std;
using point = pair<ll, ll>;
using line = pair<point, point>;
line l1;
line l2;

inline int ccw(point a, point b, point c) { ll dir = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x); return (dir > 0) - (dir < 0); }

bool cross(line l1, line l2) {
	ll ab = ccw(l1.first, l1.second, l2.first) * ccw(l1.first, l1.second, l2.second);
	ll cd = ccw(l2.first, l2.second, l1.first) * ccw(l2.first, l2.second, l1.second);
	if (ab == 0 && cd == 0) {
		if (l1.first > l1.second) {
			swap(l1.first, l1.second);
		}
		if (l2.first > l2.second) {
			swap(l2.first, l2.second);
		}
		return !(l1.second < l2.first || l1.first > l2.second);
	}
	return ab <= 0 && cd <= 0;
}

int main()
{
	cin >> l1.first.x >> l1.first.y >> l1.second.x >> l1.second.y;
	cin >> l2.first.x >> l2.first.y >> l2.second.x >> l2.second.y;
	if (cross(l1, l2)) {
		cout << 1 << '\n';
		long double a1 = (long double)(l1.second.y - l1.first.y) / (l1.second.x - l1.first.x);
		long double a2 = (long double)(l2.second.y - l2.first.y) / (l2.second.x - l2.first.x);
		long double b1 = -a1 * l1.first.x + l1.first.y;
		long double b2 = -a2 * l2.first.x + l2.first.y;
		long double k = (b1 - b2) / (a2 - a1);
		long double y1 = a1 * (k - l1.first.x) + l1.first.y;
		if (!(isnan(a1) || isnan(a2))) {
			if (!isnan(a1)) {
				cout << l1.first.x << ' ' << a2 * l1.first.x + b2;
			}
			else {
				cout << l2.first.x << ' ' << a1 * l2.first.x + b1;
			}
		}
		else {
			if (isnan(k) || isnan(y1)) {
				if (l1.first == l2.second || l1.first == l2.first) {
					cout << l1.first.x << ' ' << l1.first.y;
				}
				else if (l1.second == l2.first || l1.second == l2.second) {
					cout << l1.second.x << ' ' << l1.second.y;
				}
			}
			else {
				printf("%.20lf %.20lf", k, y1);
			}
		}
	}
	else {
		cout << 0;
	}
}