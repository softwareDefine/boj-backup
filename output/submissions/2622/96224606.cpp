#include <bits/stdc++.h>

using namespace std;

long long cnt;
long long n;

int main(){
    cin >> n;
    for(int i=(n-1)/2;i>=1;i--){
        for(int j=n/4+1;j<=i;j++){
            if((n-(i+j)) > 0 && (n-(i+j))<=i){
                //cout << i << ' ' << j << ' ' << n-(i+j) << '\n';
                cnt++;
            }
        }
    }
    cout << cnt;
}