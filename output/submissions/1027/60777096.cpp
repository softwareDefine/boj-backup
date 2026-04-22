#define x first
#define y second
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using point = pair<long long, long long>;

ll arr[100010];
ll cnt[100100];
ll mmx;
ll n;

int ccw(point a, point b, point c) {
	ll res = a.x * b.y + b.x * c.y + c.x * a.y;
	res -= a.y * b.x + b.y * c.x + c.y * a.x;
	return (res > 0) - (res < 0);
}

bool cross(point a, point b, point c, point d) {
	ll ab = ccw(a, b, c) * ccw(a, b, d);
	ll cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b) {
			swap(a, b);
		}
		if (b > c) {
			swap(b, c);
		}
		return !(b < c || a > d);
	}
	return (ab <= 0 && cd <= 0);
}

bool check(point c,point d) {
	int mmx = max(c.x, d.x);
	int mmn = min(c.x, d.x);
	for (int i = mmn+1; i < mmx; i++) {
		if (cross({ i,0 }, { i,arr[i] }, c, d)) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			if (check({ i, arr[i] }, { j,arr[j] })) {
				cnt[i]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		mmx = max(mmx, cnt[i]);
	}
	cout << mmx;
}