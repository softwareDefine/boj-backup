#define x first
#define y second
#include <iostream>
#include <math.h>

using namespace std;
using point = pair<long long, long long>;

int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		point p1, p2;
		long long r1, r2;
		cin >> p1.x >> p1.y;
		cin >> r1;
		cin >> p2.x >> p2.y;
		cin >> r2;
		double getter = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));;
		if (getter == 0) {
			if(r1 == 0 && r2 ==0){
				cout << 1 << '\n';
			}
			else if (r1 == r2) {
				cout << -1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (getter == r1 + r2) {
			cout << 1 << '\n';
		}
		else if (getter > r1 + r2) {
			cout << 0 << '\n';
		}
		else if (getter < r1 + r2) {
			long long mmx = max(r1, r2);
			long long mmn = min(r1, r2);
			if (mmx - mmn == getter) {
				cout << "1" << '\n';
			}
			else if (mmx - mmn > getter) {
				cout << "0" << '\n';
			}
			else {
				cout << "2" << '\n';
			}
		}
	}

}