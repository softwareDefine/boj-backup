#include <bits/stdc++.h>

using namespace std;

int t;

string dp[2000];

int main(){
    for(int i=1;i<2000;i++){
        dp[i] = "999999999999";
    }
    dp[1] = "12";
    dp[2] = "34";
    dp[3] = "56";
    for(int i=4;i<=1000;i++){
        if(!(i%2)){
            dp[i] = to_string(min(stoull(dp[i]),stoull('1'+dp[i/2]+'2')));
        }
        if(!(i%3)){
            dp[i] = to_string(min(stoull(dp[i]),stoull('3'+dp[i/3]+'4')));
        }
        if(!(i%5)){
            dp[i] = to_string(min(stoull(dp[i]),stoull('5'+dp[i/5]+'6')));
        }
        for(int j=1;j<i;j++){
            dp[i] = to_string(min(stoull(dp[i]),stoull(dp[j]+dp[i-j])));
            dp[i] = to_string(min(stoull(dp[i]),stoull(dp[i-j]+dp[j])));
        }
    }
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << '\n'; 
    }
}