#include <bits/stdc++.h>

using namespace std;

int t,k;
int dp[20000];
int p[200];
int n[200];
int main(){
    cin >> t;
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> p[i] >> n[i];
    }
    dp[0] = 1;
    for(int i=0;i<k;i++){
        for(int c=t;c>=0;c--){
            for(int j=1;j<=n[i];j++){
                if(dp[c]){dp[c+(p[i]*j)] += dp[c];}
            }
        }
    }
    cout << dp[t];
}