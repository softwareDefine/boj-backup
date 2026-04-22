#include <iostream>

using namespace std;

long long n;
long long arr[100010],dp[100010];
long long mdp[100010];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(max(arr[0]+arr[2], arr[1]+arr[2]),arr[1]+arr[0]);
	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 2]+arr[i],max(dp[i-3]+arr[i-1]+arr[i], dp[i - 1]));
	}
	long long mmx = dp[0];
	for (int i = 1; i < n; i++) {
		mmx = max(dp[i], mmx);
	}
	cout << mmx;
}