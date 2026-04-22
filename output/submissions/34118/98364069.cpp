#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n;

string a;
string b;

lint arr[5000];
lint brr[5000];
lint p1,p3,p5,ppair;
lint dp[5000][5000];

lint go(int korea,int koi){
    if(dp[korea][koi] != 9999999999999999){return dp[korea][koi];}
    if(korea > n+9 && koi > n+9){
        return 0;
    }
    int checker[10] = {0, };
    if(korea + 1 > 9){
        checker[0] = 1;
    }
    if(korea + 3 > 9){
        checker[1] = 1;
    }
    if(korea + 5 > 9){
        checker[2] = 1;
    }
    if(koi + 1 > 9){
        checker[3] = 1;
    }
    if(koi + 3 > 9){
        checker[4] = 1;
    }
    if(koi + 5 > 9){
        checker[5] = 1;
    }
    if(korea + 4 > 9){
        checker[6] = 1;
    }
    dp[korea][koi] = min(dp[korea][koi],go(korea+1,koi+1) + checker[0]*arr[korea]*p1 + checker[3]*brr[koi]*p1);
    dp[korea][koi] = min(dp[korea][koi],go(korea+1,koi+3)+ checker[0]*arr[korea]*p1 + checker[4]*p3);
    dp[korea][koi] = min(dp[korea][koi],go(korea+1,koi+5)+ checker[0]*arr[korea]*p1 + checker[5]*p5);
    dp[korea][koi] = min(dp[korea][koi],go(korea+3,koi+1)+ checker[1]*p3 + checker[3]*brr[koi]*p1);
    dp[korea][koi] = min(dp[korea][koi],go(korea+3,koi+3)+ checker[1]*p3 + checker[4]*p3);
    dp[korea][koi] = min(dp[korea][koi],go(korea+3,koi+5)+ checker[1]*p3 + checker[5]*p5);
    dp[korea][koi] = min(dp[korea][koi],go(korea+5,koi+1)+ checker[2]*p5 + checker[3]*brr[koi]*p1);
    dp[korea][koi] = min(dp[korea][koi],go(korea+5,koi+3)+ checker[2]*p5 + checker[4]*p3);
    dp[korea][koi] = min(dp[korea][koi],go(korea+5,koi+5)+ checker[2]*p5 + checker[5]*p5);
    if(korea == koi){
        dp[korea][koi] = min(dp[korea][koi],go(korea+4,koi+4)+ checker[6]*ppair);
    }
    return dp[korea][koi];
}

int main() {
    for(int i=0;i<4500;i++){
        for(int j=0;j<4500;j++){
            dp[i][j] = 9999999999999999;
        }
    }
    cin >> n;
    cin >> a;
    cin >> b;
    //dp[0][0] = 0;
    for(int i=0; i<n; i++) {
        arr[i+10]=a[i]-'0';
    }
    for(int i=0; i<n; i++) {
        brr[i+10]=b[i]-'0';
    }
    cin >> p1 >> p3 >> p5 >> ppair;
    cout << go(0,0);
}