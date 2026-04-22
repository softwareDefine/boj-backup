#include <iostream>
#include <vector>

using namespace std;

typedef struct hi {
	int cost1;
	int cost2;
	int cost3;
}h;

vector<h> vc;
int dp[100010][3];
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vc.push_back({a,b,c});
	}
	dp[0][0] = vc[0].cost1;
	dp[0][1] = vc[0].cost2;
	dp[0][2] = vc[0].cost3;
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2])+vc[i].cost1;
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + vc[i].cost2;
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + vc[i].cost3;
	}
	cout << min(min(dp[n - 1][0], dp[n - 1][1]), dp[n-1][2]);
}