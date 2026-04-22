#include <bits/stdc++.h>

using namespace std;

int n;

string a;
string b;

int arr[3000];
int brr[3000];
int p1,p3,p5,ppair;
int dp[3000][3000];

int go(int korea,int koi){
    if(dp[korea][koi] != 999999999){return dp[korea][koi];}
    if(korea > n-1 && koi > n-1){
        return 0;
    }
    dp[korea][koi] = min(dp[korea][koi],go(korea+1,koi+1) + arr[korea]*p1 + brr[koi]*p1);
    dp[korea][koi] = min(dp[korea][koi],go(korea+1,koi+3)+ arr[korea]*p1 + p3);
    dp[korea][koi] = min(dp[korea][koi],go(korea+1,koi+5)+ arr[korea]*p1 + p5);
    dp[korea][koi] = min(dp[korea][koi],go(korea+3,koi+1)+ p3 + arr[koi]*p1);
    dp[korea][koi] = min(dp[korea][koi],go(korea+3,koi+3)+ p3 + p3);
    dp[korea][koi] = min(dp[korea][koi],go(korea+3,koi+5)+ p3 + p5);
    dp[korea][koi] = min(dp[korea][koi],go(korea+5,koi+1)+ p5 + brr[koi]*p1);
    dp[korea][koi] = min(dp[korea][koi],go(korea+5,koi+3)+ p5 + p3);
    dp[korea][koi] = min(dp[korea][koi],go(korea+5,koi+5)+ p5 + p3);
    dp[korea][koi] = min(dp[korea][koi],go(korea+4,koi+4)+ ppair);
    return dp[korea][koi];
}

int main() {
    for(int i=0;i<3000;i++){
        for(int j=0;j<3000;j++){
            dp[i][j] = 999999999;
        }
    }
    cin >> n;
    cin >> a;
    cin >> b;
    //dp[0][0] = 0;
    for(int i=0; i<n; i++) {
        arr[i]=a[i]-'0';
    }
    for(int i=0; i<n; i++) {
        brr[i]=b[i]-'0';
    }
    cin >> p1 >> p3 >> p5 >> ppair;
    cout << go(0,0);
}