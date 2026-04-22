#define mod 1000000009
#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n, k;
lint dp[2000000];

int main(){
    cin >> n >> k;
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        dp[i] = ((dp[i-1] % mod)*k)%mod - (2*(i-5 >= 0 ? dp[i-5]%mod : 0 ))%mod;
        if(i >= 7){
            dp[i] = (dp[i-7]%mod + dp[i]%mod)%mod;
        }
    }
    cout << (dp[n] + mod)%mod;
}