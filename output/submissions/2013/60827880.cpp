#define x first
#define y second
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>

constexpr double EPS = 1e-7;

using namespace std;
using ll = long long;
using point = pair<long long, long long>;
//정휘 쌤 참고 부분
struct Line {
	point p1, p2; ll dx, dy;
	friend istream& operator >> (istream& in, Line& l) {
		double x1, y1, x2, y2;
		in >> x1 >> y1 >> x2 >> y2;
		l.p1.x = floor(x1 * 100 + EPS);
		l.p1.y = floor(y1 * 100 + EPS);
		l.p2.x = floor(x2 * 100 + EPS);
		l.p2.y = floor(y2 * 100 + EPS);
		if (l.p1 > l.p2) swap(l.p1, l.p2);
		l.dx = l.p2.x - l.p1.x;
		l.dy = l.p2.y - l.p1.y;
		return in;
	}
};
vector<Line> vc;
int n;
int cnt;
int parent[5000100];

inline ll ccw(point p1, point p2,point p3) {
	return(p2.x - p1.x) * (p3.y - p2.y) - (p3.x - p2.x) * (p2.y - p1.y);
}

bool cross(Line a1,Line b1) {
	if (a1.dx * b1.dy != b1.dx * a1.dy) return false;
	auto a = a1.p1, b = a1.p2, c = b1.p1, d = b1.p2;
	if (ccw(a, b, c) != 0) return false;
	if (a > b) swap(a, b);
	if (c > d) swap(c, d);
	return !(b < c || d < a);
}

int finder(int now) {
	if (parent[now] == now) {
		return now;
	}
	return parent[now] = finder(parent[now]);
}
void merge(int st, int ed) {
	int stp = finder(st);
	int edp = finder(ed);
	if (stp != edp) {
		if (stp > edp) {
			parent[stp] = edp;
		}
		else {
			parent[edp] = stp;
		}
	}
}set<int> st;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		Line a;
		cin >> a;
		vc.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			if (finder(i) != finder(j) && cross(vc[i], vc[j])) {
				merge(i, j);
				cnt++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (st.find(parent[i]) == st.end()) {
			st.insert(i);
		}
	}
	cout << st.size();
}