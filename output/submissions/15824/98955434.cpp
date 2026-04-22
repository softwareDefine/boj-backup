#define mod 1000000007
#include <bits/stdc++.h>


using lint = long long;
using namespace std;

int n;
lint power[400000];
lint arr[400000];

lint ans;

int main(){
    power[0] = 1;
    for(int i=1;i<=300000;i++){
        power[i] = (power[i-1]*2)%mod;
    }
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        ans = (ans%mod + (arr[i]%mod *(power[i]-power[n-1-i])%mod)%mod)%mod;
    }
    cout << ((ans%mod) + mod)%mod;
}