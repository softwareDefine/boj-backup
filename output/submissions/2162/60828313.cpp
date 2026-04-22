#define x first
#define y second
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;
using point = pair <ll, ll>;

ll parent[100010];
int n;
int cnt;
ll mmx = -999999999;
vector<pair<point,point>> vc;
map < ll, ll> mp;
int ccw(point a, point b, point c) {
	ll res = a.x*b.y + b.x*c.y + c.x*a.y;
	res -= a.y*b.x + b.y*c.x + c.y*a.x;
	return (res > 0) - (res < 0);
}

bool cross(point a, point b, point c, point d) {
	int ab = ccw(a, b, c)*ccw(a, b, d);
	int cd = ccw(c, d, a)*ccw(c, d, b);
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

int finder(int now) {
	if (parent[now] == now) {
		return now;
	}
	return parent[now] = finder(parent[now]);
}

void merge(int st, int ed) {
	ll stp = finder(st);
	ll edp = finder(ed);
	if (stp != edp) {
		if (stp > edp) {
			parent[stp] = edp;
		}
		else {
			parent[edp] = stp;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		point a, b;
		cin >> a.x >> a.y;
		cin >> b.x >> b.y;
		vc.push_back({ a,b });
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			if (cross(vc[i].first, vc[i].second, vc[j].first, vc[j].second)) {
				if (finder(i) != finder(j)) {
					merge(i, j);
				}
			}
			
		}
	}
	for (int i = 0; i < n; i++) {
		if (mp.find(finder(i)) == mp.end()) {
			mp.insert({finder(i),1 });
		}
		else {
			mp[finder(i)]++;
		}
	}
	for (auto i : mp) {
		mmx = max(i.second, mmx);
	}
	cout << mp.size()<< '\n' ;
	cout << mmx;
}