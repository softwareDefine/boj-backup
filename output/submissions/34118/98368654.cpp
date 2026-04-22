#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n;

string a;
string b;

lint arr[9000];
lint brr[9000];
lint p1,p3,p5,ppair;
lint dp[9000][9000];

lint go(lint korea,lint koi) {
 	korea = min(korea,n+2LL);
	koi = min(koi,n+2LL);
	if(dp[korea][koi] != 999999999) {
		return dp[korea][koi];
	}
	if(korea > n && koi > n) {
		return 0;
 	}
	dp[korea][koi] = min(dp[korea][koi],go(korea+1,koi+1) + arr[korea]*p1 + brr[koi]*p1);
	for(int i=1;i<=1; i++) {
		for(int j=1; j<=3; j++) {
			dp[korea][koi] = min(dp[korea][koi],go(korea+i,koi+j)+ arr[korea]*p1 + p3);
		}
	}
	for(int i=1; i<=1; i++) {
		for(int j=1; j<=5; j++) {
			dp[korea][koi] = min(dp[korea][koi],go(korea+i,koi+j)+ arr[korea]*p1 + p5);
		}
	}
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=1; j++) {
			dp[korea][koi] = min(dp[korea][koi],go(korea+i,koi+j)+ p3 + brr[koi]*p1);
		}
	}
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=3; j++) {
			dp[korea][koi] = min(dp[korea][koi],go(korea+i,koi+j)+ p3 + p3);
		}
	}
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=5; j++) {
			dp[korea][koi] = min(dp[korea][koi],go(korea+i,koi+j)+ p3 + p5);
		}
	}
	for(int i=1; i<=5; i++) {
		for(int j=1; j<=1; j++) {
			dp[korea][koi] = min(dp[korea][koi],go(korea+i,koi+j)+ p5 + brr[koi]*p1);
		}
	}
	for(int i=1; i<=5; i++) {
		for(int j=1; j<=3; j++) {
			dp[korea][koi] = min(dp[korea][koi],go(korea+i,koi+j)+ p5 + p3);
		}
	}
	for(int i=1; i<=5; i++) {
		for(int j=1; j<=5; j++) {
			dp[korea][koi] = min(dp[korea][koi],go(korea+i,koi+j)+ p5 + p5);
		}
	}
	if(korea == koi){
			dp[korea][koi] = min(dp[korea][koi],go(korea+4,koi+4)+ ppair);
	}
	return dp[korea][koi];
}

int main() {
	for(int i=0; i<6000; i++) {
		for(int j=0; j<6000; j++) {
			dp[i][j] = 999999999;
		}
	}
	cin >> n;
	cin >> a;
	cin >> b;
	for(int i=0; i<n; i++) {
		arr[i]=a[i]-'0';
	}
	for(int i=0; i<n; i++) {
	    
		brr[i]=b[i]-'0';
	}
	cin >> p1 >> p3 >> p5 >> ppair;
	cout << go(0,0);
}