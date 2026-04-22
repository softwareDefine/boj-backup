#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint dp[23][23][23];

lint go(int a, int b, int c){
    if( a <= 0 || b <= 0 || c <= 0){
        return 1;
    }
    if( a > 20 || b > 20 || c > 20 ){
        return go(20, 20, 20);
    }
    if(dp[a][b][c]){ return dp[a][b][c]; }
    if( a < b && b < c ){
        return dp[a][b][c] = go(a, b, c-1) + go(a, b-1, c-1) - go(a, b-1, c);
    }
    return dp[a][b][c] = go(a-1, b, c) + go(a-1, b-1, c) + go(a-1, b, c-1) - go(a-1, b-1, c-1);
}


int main(){
    while(1){
        lint a,b,c;
        cin >> a >> b >> c;
        if( a == b && b == c && c == -1){
            return 0;
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << go(a, b, c) << '\n';
    }
}