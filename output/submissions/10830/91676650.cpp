#define mod 1000
#include<bits/stdc++.h>

using namespace std;
long long n,b;
vector<vector<long long>> arr;

vector<vector<long long>> operator*(const vector<vector<long long>> &a, const vector<vector<long long>> &b){
    vector<vector<long long>> c;
    c.clear();
    for(int i=0;i<n;i++){
        vector<long long> tmp;
        tmp.clear();
        for(int j=0;j<n;j++){
            long long sum = 0;
            for(int k=0;k<n;k++){
                sum=(((a[i][k]%mod) *(b[k][j] %mod))%mod + sum%mod)%mod;
            }
            tmp.push_back(sum);
        }
        c.push_back(tmp);
    }
    return c;
}


vector<vector<long long>> DnC(int now){
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
    cin >> n >> b;
    for(int i=0;i<n;i++){
        vector<long long> tmp;
        tmp.clear();
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        arr.push_back(tmp);
    }
    vector<vector<long long>> ans = DnC(b);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << ans[i][j] % mod << ' ';
        }
        cout << '\n';
    }
}