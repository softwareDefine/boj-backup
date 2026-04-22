#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint dp[100]; 
vector<lint> vc;
lint ans = 1;

lint n,m;

int main(){
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=60;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cin >> n;
    vc.push_back(0);
    cin >> m;
    for(int i=0;i<m;i++){
        int k;
        cin >> k;
        vc.push_back(k);
    }
    vc.push_back(n+1);
    for(int i=1;i<vc.size();i++){
        ans *= dp[(vc[i] - vc[i-1]-1)]; 
    }
    cout << ans;
}