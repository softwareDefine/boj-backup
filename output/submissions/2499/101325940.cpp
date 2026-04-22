#include <bits/stdc++.h>

using namespace std;

int n;

typedef struct{
    int i;
    int j;
    int val;
}Node;

int mp[30][30];
int dp[24][24][90000];
int sum[30][30];
int diff[30][30];
vector<int> rev;
int mmn = 99999999, mmnidx = 0;

queue<Node> qu;

int main(){
    cin >> n;
    for(int i = n; i >= 1 ;i--){
        for(int j = 1; j <= n ; j++ ){
            cin >> mp[i][j];
        }
    }
    for(int i = 0; i < 24; i++){
        for(int j = 0; j < 24; j++){
            for(int k = 0; k < 90000; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    for(int j = 1 ; j <= n ; j++){
        for(int i = 1; i <= n ; i++){
            sum[i][j] = sum[i-1][j] + mp[i][j];
        }
        for(int i = 0; i <= n ; i++){
            diff[i][j] = sum[i][j] - (sum[n][j] - sum[i][j]);
        }
    }
    qu.push({0, 0, 0});
    while(!qu.empty()){
        int i = qu.front().i;
        int j = qu.front().j;
        int val = qu.front().val;
        qu.pop();
        if( j == n ){
            if(abs(mmn) > abs(val)){
                mmn = val;
                mmnidx = i;
            }
            continue;
        }
        for(int a = i; a <= n; a++){
            if(dp[a][j+1][val+diff[a][j+1]+40000] == -1){
                qu.push({a,j+1,val+diff[a][j+1]});
                dp[a][j+1][val+diff[a][j+1]+40000] = i;
            }
        }
    }
    cout << abs(mmn) << '\n';
    int j = n;
    for(int j = n; j >= 1; j--){
        rev.push_back(mmnidx);
        int nmmn = diff[mmnidx][j];
        mmnidx = dp[mmnidx][j][mmn+40000];
        mmn -= nmmn;
        //cout << mmnidx << '\n';
    }
    reverse(rev.begin(),rev.end());
    for(auto element : rev){
        cout << element << ' ';
    }
}