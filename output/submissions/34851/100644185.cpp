#define mod 1000000007
#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n;
lint ans;

int main(){
    cin >> n;
    for(int i=0;i<n+1;i++){
        lint tmp;
        cin >> tmp;
        if(i == 0){
            ans = (tmp % mod);
        }else{
            if(tmp == 1 || ans == 1){
                ans = (ans%mod + tmp%mod)%mod;
            }else{
                ans = ((ans%mod)*(tmp%mod))%mod;
            }
        }
    }
    cout << ans;
}