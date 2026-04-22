// a-471.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using ll = long long;
using namespace std;

int n, divide;
ll dp[110][110];
bool visit[110][110];
ll sum[110];
ll arr[110];

ll go(int cnt,int end) {
	if (cnt == 0 ) { return 0; }
	if (end <= 0) { return -32768 * 101; }
	if (visit[cnt][end]) { return dp[cnt][end]; }
	visit[cnt][end] = 1;
	dp[cnt][end] = go(cnt ,end-1);
	ll sum = 0;
	for (int i = end; i >= 1; i--) {
		sum += arr[i];
		dp[cnt][end] = max(dp[cnt][end],go(cnt - 1, i - 2) + sum);
	}
	return dp[cnt][end];
}

int main()
{
	cin >> n >> divide;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cout << go(divide, n);
}