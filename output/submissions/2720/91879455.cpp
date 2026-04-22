#include<bits/stdc++.h>

using namespace std;

int t;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while(t--){
        int c;
        cin >> c;
        int q = c/25;
        c %= 25;
        int d = c/10;
        c %= 10;
        int n = c/5;
        c %= 5;
        int p = c;
        cout << q << ' ' << d << ' ' << n << ' ' << p << '\n';
    }
}