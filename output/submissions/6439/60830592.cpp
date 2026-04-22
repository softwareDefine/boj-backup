#define x first
#define y second
#include <iostream>

using namespace std;
using ll = long long;
using point = pair<ll, ll>;


int n;

int ccw(point a, point b, point c) {
	ll res = a.x * b.y + b.x * c.y + c.x * a.y;
	res -= a.y * b.x + b.y * c.x + c.y * a.x;

	return (res > 0) - (res < 0);
}

bool cross(point a, point b, point c, point d) {
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b) {
			swap(a, b);
		}
		if (c > d) {
			swap(c, d);
		}
		return !(b < c || a > d);
	}
	return ab <= 0 && cd <= 0;
}

bool check(point arr[4], point c, point d) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int j = (i + 1 == 4) ? 0 : i + 1;
		if (ccw(arr[i],arr[j],c) == 1 &&ccw(arr[i], arr[j], d) == 1) {
			cnt++;
		}
	}
	if (cnt == 4) {
		return 1;
	}
	for (int i = 0; i < 4; i++) {
		int j = (i + 1 == 4) ? 0 : i + 1;
		if (cross(arr[i], arr[j], c, d)) {
			return 1;
		}
	}
	return 0;
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		point arr[4],a,b, c, d;
		
		cin >> c.x >> c.y;
		cin >> d.x >> d.y;
		cin >> a.x >> a.y;
		cin >> b.x >> b.y;

		if (a.x < b.x) {
			if (a.y < b.y) {
				arr[1] = a;
				arr[3] = b;
				arr[0] = {a.x,b.y};
				arr[2] = {b.x,a.y};
			}
			else {
				arr[0] = a;
				arr[1] = { a.x,b.y };
				arr[2] = b;
				arr[3] = { b.x,a.y };
			}
		}
		else {
			if (a.y < b.y) {
				arr[2] = a;
				arr[0] = b;
				arr[1] = { b.x,a.y };
				arr[3] = { a.x,b.y };
			}
			else {
				arr[3] = a;
				arr[1] = b;
				arr[0] = { b.x,a.y };
				arr[2] = { a.x,b.y };
			}
		}
		if (check(arr, c, d)) {
			cout << "T" << '\n';
		}
		else {
			cout << "F" << '\n';
		}
	}
	
}