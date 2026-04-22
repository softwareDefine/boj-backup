#include <bits/stdc++.h>

using namespace std;

int n;

int arr[2000][3];
int dp[2000][3][3];

int mmn = 999999999;

int main(){
    for(int i=0;i<2000;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                dp[i][j][k] = 999999999;
            }
        }
    }
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2]; 
    }
    for(int i=1;i<=n;i++){
        if(i==1){
            dp[i][0][0] = arr[i][0];
            dp[i][1][1] = arr[i][1];
            dp[i][2][2] = arr[i][2];
            continue;
        }else if(i == n){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(j!=k){
                        dp[i][j][k] = min(dp[i-1][(j+1)%3][k], dp[i-1][(j+2)%3][k]) + arr[i][j];
                        mmn = min(mmn,dp[i][j][k]);
                    }
                }
            }
            continue;
        }
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                dp[i][j][k] = min(dp[i-1][(j+1)%3][k], dp[i-1][(j+2)%3][k]) + arr[i][j];
            }
        }
    }
    cout << mmn;
}