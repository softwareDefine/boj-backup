#include <iostream>

#include <vector>

using namespace std;

long long n;

vector<pair<long long,long long>> vc;

long long mmx = 1e9;

int ccw(pair<long long, long long> &a, pair<long long, long long> &b, pair<long long, long long> &c) {

	long long cnt = a.first* b.second + b.first * c.second + c.first * a.second;	cnt -= a.second * b.first + c.first * b.second + a.first * c.second;

	return (cnt > 0) - (cnt < 0);

}

int Cross(pair<long long, long long> &a, pair<long long, long long> &b, pair<long long, long long> &c, pair<long long, long long> &d) {

	long long ab = ccw(a,b,c)*ccw(a,b,d);

	long long cd = ccw(c, d, a)*ccw(c, d, b);

	if (ab == 0 && cd == 0) {

		if (a > b) {

			swap(a, b);

		}

		if (c > d) {

			swap(c, d);

		}

		return !(b < c || d < a);

	}

	return ab <= 0 && cd <= 0;

}

int check(vector<pair<long long, long long>> &v, pair<long long, long long> p1) {

	long long n = v.size(), cnt = 0;

	pair<long long, long long>p2 = {mmx + 1, p1.second + 1};

	for (long long i = 0; i < n; i++) {

		long long j = (i + 1 == n) ? 0 : i + 1;

		if (ccw(v[i],v[j],p1)==0 && min(v[i],v[j]) <= p1 && max(v[i],v[j]) >= p1) {

			return 1;

		}

		cnt += Cross(v[i], v[j], p1, p2);

	}

	return cnt & 1;

}

int main()

{

	cin >> n;

	for (long long i = 0; i < n; i++) {

		long long x, y;

		cin >> x >> y;

		vc.push_back({ x,y });

	}

	for (long long i = 0; i < 3; i++) {

		long long x, y;

		cin >> x >> y;

		cout << check(vc,{x,y}) << '\n';

	}

}