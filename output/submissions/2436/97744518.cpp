#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll gcd1, lcm1;
ll pos;
pair<ll,ll> ans;

int main(){
    cin >> gcd1 >> lcm1;
    pos=lcm1/gcd1;
    for(int i=1;i*i<=pos;i++){
        if(!(pos%i) && gcd(i,pos/i) == 1){
            ans = {i*gcd1,(pos/i)*gcd1};
        }
    }
    cout << ans.first << ' ' << ans.second;
}