#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int n, k;
int g;
vector < ll > vc[200];
ll sumup[3010][3010];
ll dp[3010][200];
ll mmx;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		ll a; int b;
		cin >> a >> b;
		vc[b].push_back(a);
		g = max(g, b);
	}
	for (int i = 1; i <= g; i++) {
		sort(vc[i].begin(), vc[i].end(), [&](auto a, auto b) { return a > b; });
		for (int j = 0; j < vc[i].size(); j++) {
			if (j == 0) {
				sumup[i][1] = vc[i][0];
				continue;
			}
			sumup[i][j + 1] = sumup[i][j] + vc[i][j];
		}
	}
	for(int i=0;i<g;i++){
		for(int j=0;j<=k;j++){
			for(int l=0;l<=vc[i+1].size();l++){
				dp[j+l][i+1] = max(dp[j+l][i+1],dp[j][i] + sumup[i+1][l] + (l)*(l-1));
			}
		}
    }
	cout << dp[k][g];
}