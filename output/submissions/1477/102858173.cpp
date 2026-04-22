#include <bits/stdc++.h>

using namespace std;

int n, m, l;

vector<int> vc;

int dp[2000][2000];

int main() {
    for(int i = 0; i < 2000; i++){
        for(int j = 0; j < 2000; j++){
            dp[i][j] = 99999999;
        }
    }
	cin >> n >> m >> l;
	vc.resize(n);
	for(auto &element : vc) {
		cin >> element;
	}
	vc.push_back(0);
	vc.push_back(l);
	sort(vc.begin(), vc.end());
	dp[0][0] = 0;
	for(int i = 0; i < vc.size()-1; i++){
	    for(int j = 0; j <= m; j++){
    	    for(int k = j; k <= m; k++){
    	        if(vc[i+1]-vc[i] < k - j - 1){ continue; }
    	        dp[i+1][k] = min(dp[i+1][k], max(dp[i][j], (vc[i+1]-vc[i])/(k-j+1) + ((vc[i+1]-vc[i])%(k-j+1)?1:0)));
    	    }
	    }
	}
	cout << dp[n][m];
	return 0;
}