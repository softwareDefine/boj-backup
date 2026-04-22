#include <bits/stdc++.h>

using namespace std;

int k,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> k;
    cin >> c;
    while(c--){
        int m,n;
        cin >> m >> n;
        int now = max(m-1,n);
        if(m > n){
        if(m + k-now >= n && (m-1) <= n +k-now){
            cout << 1 << '\n';
        }else{
            cout << 0 << '\n';
        }
        }else{
            if(m + k-now >= (n-1) && (m-1) <= n +k-now){
                cout << 1 << '\n';
            }else{
                cout << 0 << '\n';
            }
        }
    }
}