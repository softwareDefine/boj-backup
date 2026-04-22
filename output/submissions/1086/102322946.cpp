#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;

lint dp[50000][110];
string number[20];
int remain[20];
int length[20];
int powmd[100];

int k;

lint lintgcd(lint a, lint b){
    if(!a){
        return b;
    }
    return lintgcd(b%a, a);
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> number[i];
		length[i] = number[i].length();
	}
	cin >> k;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < length[i]; j++) {
			remain[i] = (remain[i]*10 + (number[i][j]-'0'))%k;
		}
	}
	powmd[0] = 1;
	for(int i = 1; i <= 50; i++){
	    powmd[i] = (powmd[i-1]*10)%k;
	}
	dp[0][0] = 1;
	for(int mask = 0; mask <= (1 << n)-1; mask++) {
		for(int nowr = 0; nowr < k; nowr++) {
			for(int next = 0; next < n; next++) {
				if(!(mask & (1 << next))) {
					int nextr = ((powmd[length[next]]*nowr)%k + remain[next])%k;
					dp[mask | (1 << next)][nextr] += dp[mask][nowr];
				}
			}
		}
	}
	lint all = 1;
	for(int i = 1; i <= n;i++){
	    all *= i;
	}
	if(all == dp[(1 << n)-1][0]){
	    cout << "1/1";
	}else if(!dp[(1 << n)-1][0]){
	    cout << "0/1";
	}else{
	cout << dp[(1 << n)-1][0]/lintgcd(all, dp[(1 << n)-1][0]) << '/' << all/lintgcd(all, dp[(1 << n)-1][0]);
	}
	return 0;
}