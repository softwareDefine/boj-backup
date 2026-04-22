#include <iostream>
#include <vector>
#define int long long
using namespace std;
int n;
int dp[4];
vector<char> vc;

signed main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a;
		cin >> a;
		if (a == 'D' || a == 'K' || a == 'H' || a == 'S') {
			vc.push_back(a);
		}
	}
	for (int i = 0; i < vc.size(); i++) {
		if (vc[i] == 'D')
		{
			dp[0]++;
		}
		else if (vc[i] == 'K')
			dp[1] += dp[0];
		else if (vc[i] == 'S')
			dp[2] += dp[1];
		else
			dp[3] += dp[2];
	}
	cout << dp[3];
}