#include <iostream>
#include <algorithm>

using namespace std;

int a,b,c,d;
int hcnt;
int sum;
int main()
{
	cin >> a >> b;
	cin >> c >> d;
	if (a > c || (a == c && b > d)) {
		c += 24;
	}
	if (d - b < 0) {
		hcnt++;
		sum += d - b + 60;
	}
	else {
		sum += d - b;
	}
	sum += (c - a - hcnt)*60;
	cout << sum  << " " << sum / 30;
}