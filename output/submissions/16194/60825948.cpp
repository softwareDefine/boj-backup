#include <iostream>


using namespace std;


int dp[10000];
int arr[10000];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = 999999;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j] + arr[j]);
		}
	}
	cout << dp[n];
}