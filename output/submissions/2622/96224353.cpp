#include <bits/stdc++.h>

using namespace std;

int cnt;
int n;

int main(){
    cin >> n;
    for(int i=n/2;i>=1;i--){
        for(int j=ceil(n/4.0);j<=i;j++){
            if((n-(i+j)) > 0 && (n-(i+j))<=i){
                //cout << i << ' ' << j << ' ' << n-(i+j) << '\n';
                cnt++;
            }
        }
    }
    cout << cnt;
}