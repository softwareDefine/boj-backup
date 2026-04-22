#define mod 1000000007
#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n;
lint ans;
lint arr[1000100];

int main(){
    cin >> n;
    for(int i=0;i<n+1;i++){
        cin >> arr[i];
        if(i == 0){
            ans = (arr[i] % mod);
        }else{
            if(arr[i] == 1 || arr[i-1] == 1){
                ans = (arr[i]%mod + arr[i]%mod)%mod;
            }else{
                ans = ((arr[i]%mod)*(arr[i]%mod))%mod;
            }
        }
    }
    cout << ans;
}