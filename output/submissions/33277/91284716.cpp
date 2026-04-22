#include<bits/stdc++.h>

using namespace std;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin >> n >> m;

    int ans = 1440*m/n;
    if(ans/60 < 10){
        cout << 0;
    }
    cout << ans/60;
    cout << ":";
    if(ans%60 < 10){
        cout << 0;
    }
    cout << ans%60; 
}