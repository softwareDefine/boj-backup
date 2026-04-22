#include <iostream>

using ll = long long;

using namespace std;

ll n, w, h;

ll dp[1000][10010];

ll sum;

int main()

{

	cin >> n >> w >> h;	for (int i = 0; i <= h; i++) {

		dp[1][i] = 1;

	}

	for (ll i = 2; i <= w; i++) {

		for (ll j = 0; j <= h; j++) {

			for (ll k = 0; k <= (i-1) * h; k++) {

				dp[i][k + j] = (dp[i - 1][k] % 1000000007 +dp[i][k+j] % 1000000007 + 1000000007)%1000000007;

			}

		}

	}

	for (ll i = 0; i <= min(n,w*h); i++) {

		sum = (dp[w][i] % 1000000007 +sum % 1000000007 + 1000000007) % 1000000007;

	}

	sum -= ((min(n,w*h) / w + 1)+1000000007)%1000000007;

   
sum = (sum+1000000007)%1000000007;
	cout << sum;

}