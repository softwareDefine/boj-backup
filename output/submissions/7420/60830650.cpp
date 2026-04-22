#include <iostream>

#include <vector>

#include <algorithm>

#include <math.h>

#define x first

#define y second

using ll = long long;

using namespace std;

using point = pair <ll,ll>;

ll n, l;

double sum;

vector<point> vc;

inline ll dist(point a, point b) {

	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);}

inline int ccw(point a, point b, point c) {

	ll dir = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);

	return (dir > 0) - (dir < 0);

}

vector<point> convexhull(vector<point>& vc) {

	swap(vc[0], *min_element(vc.begin(), vc.end()));

	sort(vc.begin() + 1, vc.end(), [&](auto a, auto b) {

		int dir = ccw(vc[0], a, b);

		return (dir == 0) ? (dist(vc[0], a) < dist(vc[0], b)) : (dir > 0);

	});

	vector<point> con;

	for (auto& i : vc) {

		while (con.size() >= 2 && ccw(con[con.size() - 2], con.back(), i) <= 0) { con.pop_back(); }

		con.push_back(i);

	}

	return con;

}

int main()

{

	cin >> n >> l;

	for (int i = 0; i < n; i++) {

		ll x1, y1;

		cin >> x1 >> y1;

		vc.push_back(make_pair(x1, y1));

	}

	vector<point> con = convexhull(vc);

	for (int i = 0; i < con.size(); i++) {

		int next = i+1;

		if (i == con.size() - 1) { next = 0; }

		sum += sqrt(dist(con[i], con[next]));

	}

	printf("%.0lf", round(sum+(double)2*M_PI*(double)l));

}