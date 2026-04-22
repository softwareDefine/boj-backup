#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <math.h>
#define x first
#define y second

using namespace std;

using point = pair<long long ,long long> ;
long long n;
vector<point> vc;

long long ccw(point a,point b,point c) {
	long long res = a.x * b.y + b.x*c.y + c.x * a.y;
	res -= a.y * b.x + c.x * b.y + a.x * c.y;
	return (res > 0) - (res < 0);
}

long long dist(point a, point b) {
	return (b.x - a.x)* (b.x - a.x) + (b.y - a.y)* (b.y - a.y);
}

bool croos(point a, point b, point c, point d) {
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int bc = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && bc == 0) {
		if (a > b) {
			swap(a, b);
		}
		if (c > d) {
			swap(c, d);
		}
		return !(b < c || d < a);
	}
	return ab <= 0 && bc <= 0;
}

vector<point> convexhull(vector<point> &points) {
	swap(points[0], *min_element(points.begin(),points.end()));
	sort(points.begin()+1, points.end(), [&](auto a, auto b) {
		long long dir = ccw(points[0], a, b);
		if (dir != 0) {
			return dir > 0;
		}
		else {
			return dist(points[0], a) < dist(points[0], b);
		}
	});
	vector<point> st;
	for (auto i : points) {
		while (st.size() >= 2 && ccw(st[st.size() - 2],st.back(),i)<=0) {
			st.pop_back();
		}
		st.push_back(i);
	}
	return st;
}
int main()
{
	cin >> n;
	for (long long i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		vc.push_back({ a,b });
	}
	auto get = convexhull(vc);
	if (get.size() <= 2) {
		cout << 0;
	}
	else {
		cout << get.size();
	}
}