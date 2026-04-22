#include <iostream>
#include <math.h>

using ll = long long;
using namespace std;

ll dp[110][110];
ll check[110][110];
ll n, m;
ll q;
int cnt =0;

int main()
{
	cin >> n >> m;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		ll k = pow(2, cnt);
		check[a][b] |= k;
		check[c][d] |= k;
		cnt++;
	}
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 && j == 0) {
				continue;
			}
			ll r = (i-1<0 || ((check[i - 1][j] & check[i][j]))) ?0 : dp[i - 1][j] ;
			ll l = (j-1<0 || ((check[i][j-1] & check[i][j]))) ? 0 : dp[i][j - 1];
			dp[i][j] = l + r;
		}
	}
	cout << dp[n][m];
}