#include <iostream>

using namespace std;
int a, b, c, d, e, f;
int mcnt;
int hcnt;
int all;
char xi;
int main()
{
	cin >> a >> xi >> b >> xi >> c;
	cin >> d >> xi >> e >> xi >> f;
	if (d < a||(d==a&&e<b)|| (d == a && e == b&&f<c)) {
		d += 24;
	}
	if (f - c < 0) {
		mcnt++;
		all = f + 60 - c;
	}
	else {
		all=f - c;
	}
	if (e - b-mcnt < 0) {
		hcnt++;
		all += (e + 60 - b-mcnt)*60;
	}
	else {
		all += (e - b-mcnt) * 60;
	}
	all += (d - a - hcnt) * 3600;
	cout << all;
}