#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n;

vector<lint> vc;

lint mmx;

int main(){
    cin >> n;
    vc.resize(n);
    for(auto &element : vc){
        cin >> element;
    }
    sort(vc.begin(), vc.end());
    for(int i = 0; i < n-2; i++){
        if(vc[i+2] < vc[i] + vc[i+1]){
            mmx = max(mmx, vc[i+2] + vc[i] + vc[i+1]);
        }
    }
    if(!mmx){ cout << -1; return 0;}
    cout << mmx;
    return 0;
}