#include <iostream>
#define mod 1000000

using ll = long long;
using namespace std;
ll dp[1000][2][3];
// 위치,지각,결석
// 지각은 0 1 까지만 가능
// 결석은 0 1 2가 마지막
int n;

int main()
{
	dp[1][0][1] = 1;
	dp[1][0][0] = 1;
	dp[1][1][0] = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
			// 출근한경우 // 결석한 경우 , 지각을 안해서 0이 된 경우
			dp[i + 1][1][0] = ((((((dp[i][1][0]%mod+dp[i][0][1]%mod)%mod+dp[i][0][2])%mod + dp[i][0][0])%mod + dp[i][1][1])%mod + dp[i][1][2])%mod + dp[i+1][1][0])%mod;
			dp[i + 1][1][1] = (dp[i][1][0]+dp[i+1][1][1])%mod;
			dp[i + 1][1][2] = (dp[i][1][1]+dp[i+1][1][2])%mod;
			dp[i + 1][0][0] = (((dp[i][0][0]+dp[i][0][1])%mod+dp[i][0][2])%mod + dp[i+1][0][0])%mod;
			dp[i + 1][0][1] = (dp[i][0][0]+dp[i+1][0][1])%mod;
			dp[i + 1][0][2] = (dp[i][0][1]+dp[i+1][0][2])%mod;
	}
	cout << (((((dp[n][0][0] + dp[n][0][1])%mod + dp[n][0][2])%mod + dp[n][1][0])%mod + dp[n][1][1])%mod + dp[n][1][2])%mod;
}