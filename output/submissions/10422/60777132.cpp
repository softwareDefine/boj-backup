#define mod 1000000007
#include <iostream>


using ll = long long;
using namespace std;

ll dp[5010];
int t,n;

int main()
{
    dp[0] = 1;
	dp[2] = 1;
	dp[4] = 2;
	for (int i = 6; i <= 5000; i += 2) {
		for (int j = i; j >= 2; j -= 2) {
			dp[i] = ((dp[j-2]%mod * dp[i - j]%mod)%mod+dp[i]%mod)%mod;
		}
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}