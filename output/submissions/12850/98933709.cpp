#define mod 1000000007
#include<bits/stdc++.h>

using namespace std;
long long n,b;
vector<vector<long long>> arr;

vector<vector<long long>> operator*(const vector<vector<long long>> &a, const vector<vector<long long>> &b){
    vector<vector<long long>> c;
    c.clear();
    for(int i=0;i<8;i++){
        vector<long long> tmp;
        tmp.clear();
        for(int j=0;j<8;j++){
            long long sum = 0;
            for(int k=0;k<8;k++){
                sum=(((a[i][k]%mod) *(b[k][j] %mod))%mod + sum)%mod;
            }
            tmp.push_back(sum);
        }
        c.push_back(tmp);
    }
    return c;
}


vector<vector<long long>> DnC(long long now){
    if(now == 1){
        return arr;
    }
    vector<vector<long long>> next = DnC(now/2);
    if(now % 2){
        return (next * next) * arr;
    }else{
        return next * next;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> b;
    arr.push_back({0,1,0,1,0,0,0,0});
    arr.push_back({1,0,1,1,0,0,0,0});
    arr.push_back({0,1,0,1,1,1,0,0});
    arr.push_back({1,1,1,0,0,1,0,0});
    arr.push_back({0,0,1,0,0,1,1,0});
    arr.push_back({0,0,1,1,1,0,0,1});
    arr.push_back({0,0,0,0,1,0,0,1});
    arr.push_back({0,0,0,0,0,1,1,0});
    vector<vector<long long>> ans = DnC(b);
    cout << ans[0][0] % mod;
}