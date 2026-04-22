#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n, m;

vector<lint> vc;
lint mmn = 0;

lint psbe(lint border){
    lint cnt = 1;
    lint smm = 0;
    for(auto minute : vc){
        if( smm + minute > border){
            cnt++;
            smm = minute;
            continue;
        }
        smm += minute;
    }
    return cnt;
}

int main(){
    cin >> n >> m;
    vc.resize(n);
    for(auto &minute : vc){
        cin >> minute;
        mmn = max(mmn, minute);
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