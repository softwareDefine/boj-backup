#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int t;

lint isNotPrime[400000];
lint ans[500000];

void era(){
    for(int i=2;i<=300000;i++){
        if(!isNotPrime[i]){
            ans[i]++;
            for(int j=i*2;j<=300000;j+=i){
                isNotPrime[j] = 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    era();
    for(int i=1;i<=300000;i++){
        ans[i] += ans[i-1];
    }
    while(1){
        int n;
        cin >> n;
        if(!n){return 0;}
        cout << ans[2*n] - ans[n] << '\n';
    }
}