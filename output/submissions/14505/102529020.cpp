#define mod 10000000000007
#include <bits/stdc++.h>

using lint = long long;
using namespace std;

string key;

lint dp[2000][2000];

lint go(int start,int end){
    if(dp[start][end] != -1){
        return dp[start][end];
    }
    if(start > end){
        return dp[start][end] = 0;
    }
    if(start == end){
        return dp[start][end] = 1;
    }
    if(key[start] != key[end]){
        return dp[start][end] = (go(start+1,end)%mod + go(start,end-1)%mod - go(start+1,end-1)%mod + mod)%mod;
    }else{
        return dp[start][end] = (go(start+1,end)%mod + go(start,end-1)%mod + 1)%mod;
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> key;
    cout << go(0,key.size()-1);
	return 0;
}