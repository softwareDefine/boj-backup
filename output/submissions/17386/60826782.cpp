#include <iostream>

using namespace std;

int ccw(long long a, long long b, long long c, long long d, long long e, long long f) {
	if (a * d + c * f + e * b - b * c - d * e - f * a < 0) {
		return -1;
	}
	else if (a * d + c * f + e * b - b * c - d * e - f * a > 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int main()
{	
	pair<long long, long long> p[4];
	for (int i = 0; i < 4; i++) {
		cin >> p[i].first >> p[i].second;
	}
	if ((ccw(p[2].first, p[2].second, p[3].first, p[3].second, p[1].first, p[1].second) * ccw(p[2].first, p[2].second, p[3].first, p[3].second, p[0].first, p[0].second) < 0) && (ccw(p[0].first, p[0].second, p[1].first, p[1].second, p[3].first, p[3].second) * ccw(p[0].first, p[0].second, p[1].first, p[1].second, p[2].first, p[2].second) < 0)) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}