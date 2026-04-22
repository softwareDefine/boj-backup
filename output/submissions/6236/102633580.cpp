#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n, m;

vector<lint> vc;
lint mmn = 100000;

lint psbe(lint mmx){
    lint wallet = 0;
    lint cnt = 0;
    for(auto price : vc){
        if(wallet - price < 0){
            wallet = mmx - price;
            cnt++;
        }else{
            wallet -= price;
        }
    }
    return cnt;
}

int main(){
    cin >> n >> m;
    vc.resize(n);
    for(auto &price : vc){
        cin >> price;
        mmn = min(mmn, price);
    }
    lint l = mmn, r = 1000000000;
    while( l < r){
        lint mid = ( l + r - 1)/2;
        if(psbe(mid) <= m){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    cout << l;
    return 0;
}