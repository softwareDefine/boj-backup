#include <bits/stdc++.h>

using namespace std;

int n,s;

pair<int,int> arr[400000];
int dp[400000];
int tmpmmx;
int mmx[400000];
int ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s;
    for(int i=1;i<=n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr+1,arr+n+1,[](auto a,auto b){
       return a.first < b.first; 
    });
    for(int i=n;i>=1;i--){
        auto lo = lower_bound(arr+1, arr+n+1, arr[i].first+s,[](const pair<int,int>& a, int x){ return a.first < x; });
        if(arr[lo-arr].first == 0){
            dp[i] = arr[i].second;
        }else{
            dp[i] = mmx[lo-arr] + arr[i].second;
        }
        tmpmmx = max(tmpmmx,dp[i]);
        mmx[i] = tmpmmx;
    }
    cout << tmpmmx;
}