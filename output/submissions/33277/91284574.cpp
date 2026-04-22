#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    double n,m;
    cin >> n >> m;

    int ans = 1440*m/n;
    
    cout << ans/60 <<':'<<ans%60; 
}