#include <iostream>

#define x first

#define y second

using namespace std;

pair<int,int> acc[1010];

int dp[1010][1010];

int n,q;

int main(){

	cin >> n >> q;	for(int i=0;i<n;i++){

		cin >> acc[i].x >> acc[i].y;

	}

	for(int i=0;i<n;i++){

		for(int j=0;j<i-1;j++){

			dp[i][j] = dp[i-1][j] +;

dp[i][i-1] = dp[j][i-1] +;

dp[j][i] = dp[j][i-1] +;

dp[i-1][i] = dp[i-1][j]+;

		}

	}

}