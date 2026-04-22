#include <iostream>
#include <string>

using namespace std;

int n;
int m;
int arr[100010];
string dp[1000010];
string mmx = "0";
bool comp(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	return a.size() <  b.size();
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	for (int i = 0; i < 1100; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i] == "0") continue;
			if (comp(dp[i+arr[j]] ,dp[i]+char(j+'0'))) {
				dp[i + arr[j]] = dp[i] + char(j + '0');
			}
		}
	}
	for (int i = m; i >= 0; i--) {
		if (comp(mmx, dp[m])) {
			mmx = dp[m];
		}
	}
	cout << mmx;
}