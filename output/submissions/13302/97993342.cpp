#include <bits/stdc++.h>

using namespace std;

int n,m;
int selective[200];
int cost[200][400];
int mmn = 999999999;

int main(){
    cin >> n >> m;
    for(int i=0;i<=200;i++){
        for(int j=0;j<=200;j++){
        cost[i][j] = 999999999;
        }
    }
    for(int i=0;i<m;i++){
        int num;
        cin >> num;
        selective[num] = 1;
    }
    cost[0][0] = 0;
    for(int i=0;i<=n;i++){
        for(int c=0;c<=200;c++){
            if(selective[i+1]){
                cost[i+1][c] = min(cost[i+1][c],cost[i][c]);
            }
            if(c >= 3){
                cost[i+1][c-3] = min(cost[i+1][c-3],cost[i][c]);
            }
            for(int j=1;j<=5;j++){
                cost[i+j][c+2] = min(cost[i+j][c+2],cost[i][c]+37000);
            }
            for(int j=1;j<=3;j++){
                cost[i+j][c+1] = min(cost[i+j][c+1],cost[i][c]+25000);
            }
            cost[i+1][c] = min(cost[i+1][c],cost[i][c]+10000);
        }
    }
    for(int i=0;i<=200;i++){
        mmn = min(mmn,cost[n][i]);
    }
    cout << mmn;
}