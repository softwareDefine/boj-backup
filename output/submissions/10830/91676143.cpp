#define mod 1000
#include<bits/stdc++.h>

using namespace std;
int n,b;
vector<vector<int>> arr;

vector<vector<int>> operator*(const vector<vector<int>> &a, const vector<vector<int>> &b){
    vector<vector<int>> c;
    c.clear();
    for(int i=0;i<n;i++){
        vector<int> tmp;
        tmp.clear();
        for(int j=0;j<n;j++){
            long long sum = 0;
            for(int k=0;k<n;k++){
                sum=((a[i][k]*b[k][j])%mod + sum)%mod;
            }
            tmp.push_back(sum);
        }
        c.push_back(tmp);
    }
    return c;
}


vector<vector<int>> DnC(int now){
    if(now == 1){
        return arr;
    }
    vector<vector<int>> next = DnC(now/2);
    if(now % 2){
        return next * next * arr;
    }else{
        return next * next;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> b;
    for(int i=0;i<n;i++){
        vector<int> tmp;
        tmp.clear();
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        arr.push_back(tmp);
    }
    vector<vector<int>> ans = DnC(b);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}