#define x first
#define y second
#include <bits/stdc++.h>

using lint = long long;
using namespace std;
using point = pair<lint, lint>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    while(1){
        int a, b;
        cin >> a >> b;
        if(!a && !b){
            return 0;
        }
        cout << a+b << '\n';
    }
    return 0;
}