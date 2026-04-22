#include <iostream>

using ll = long long;
using namespace std;

int n;
int dp[50][50010];
bool visit[50][50010];
int arr[500010];
int g;

int go(int cnt,int end) {
	if (cnt == 0 ) { return 0; }
	if (end <= 0) { return -9999999; }
	if (visit[cnt][end]) { return dp[cnt][end]; }
	visit[cnt][end] = 1;
	dp[cnt][end] = go(cnt ,end-1);
    int sum = 0;
	for (int i = end; i > max(end-g,0); i--) {
		sum += arr[i];
    }
    int k = max(end-g,0);
    dp[cnt][end] = max(dp[cnt][end], go(cnt - 1, k) + sum);
	return dp[cnt][end];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> g;
	go(3,n);
	cout << dp[3][n];
}