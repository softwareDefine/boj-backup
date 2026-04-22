#include <iostream>

using namespace std;

int mmn, mmx;
int n, k;
pair<int,int> dp;
int add[1000010];
int del[1000010];
int chk[1000010];

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> del[i] >> add[i];
	}
	for (int i = 0; i * k + 1 < n; i++) {
		chk[i * k + 1] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (chk[i]) {
			dp.second -= del[i];
			mmx += del[i];
			if (dp.second < 0) {
				dp.first += dp.second;
				mmx += dp.second;
			}
			dp.second = 0;
			dp.first += dp.second;
			dp.first += add[i];
		}
		else {
			dp.second -= del[i];
			mmx += del[i];
			if (dp.second < 0) {
				dp.first += dp.second;
				mmx += dp.second;
				dp.second = 0;
			}
			dp.second += add[i];
		}
	}
	dp.first = 0;
	dp.second = 0;
	for (int i = 1; i <= n; i++) {
		if (chk[i]) {
			dp.first -= del[i];
			if (dp.first < 0) {
				mmn += abs(dp.first);
				dp.second += dp.first;
				dp.first = 0;
			}
			dp.first += dp.second;
			dp.first += add[i];
			dp.second = 0;
		}
		else {
			dp.first -= del[i];
			if (dp.first < 0) {
				mmn += abs(dp.first);
				dp.second += dp.first;
				dp.first = 0;
			}
			dp.second += add[i];
		}
	}
	cout << mmn << ' ' << mmx;
}