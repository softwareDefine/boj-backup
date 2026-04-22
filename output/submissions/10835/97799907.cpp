#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int n;

ll arr[10010];
ll brr[10010];

ll dp[3000][3000];
ll mmx;

int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	for(int i=0; i<n; i++) {
		cin >> brr[i];
	}
	//go(0,0);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
			dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]);
			if(arr[i] > brr[j]){
			dp[i][j+1] = max(dp[i][j+1],dp[i][j] + brr[j]);
			}
		}
	}
	for(int i=0;i<=n;i++){
	    mmx = max(mmx,dp[i][n]);
	    mmx = max(mmx,dp[n][i]);
	}
	cout << mmx;
}