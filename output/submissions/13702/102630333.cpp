#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n, k;

vector<lint> vc;

lint psb(int quote){
    lint cnt = 0;
    for(auto ml : vc){
        cnt += ml/quote; 
    }
    return cnt;
}

int main(){
    cin >> n >> k;
    vc.resize(n);
    for(auto &ml : vc){
        cin >> ml;
    }
    lint l = 1, r = pow(2,31)-1;
    while( l < r ){
        lint mid = ( l + r +1 )/2;
        if(psb(mid) >= k ){
            l = mid;
        }else{
            r = mid-1;
        }
    }
    cout << l;
    return 0;
}