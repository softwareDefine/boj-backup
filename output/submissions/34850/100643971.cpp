#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint x, y, p, a, b;
lint ans;

int main(){
    cin >> x >> y >> p >> a >> b;
    cout << p*x + b*(y-1)*x - a*(x-1)*x/2;
}