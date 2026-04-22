#define mod 1000000007
#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n;
lint ans;
lint arr[10001000];

int main(){
    cin >> n;
    for(int i=0;i<n+1;i++){
        cin >> arr[i];
        if(i == 0){
            ans = (arr[i] % mod);
        }else{
            if((arr[i] == 1) || (arr[i-1] == 1)){
                ans = ((arr[i]%mod) + (ans%mod))%mod;
            }else{
                ans = ((arr[i]%mod)*(ans%mod))%mod;
            }
        }
    }
    cout << ans;
}