#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;
vector<int> vc;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vc.resize(n*n);
    for(auto &element : vc){
        cin >> element;
    }
    sort(vc.begin(), vc.end());
    cout << vc[n*n - (n)];
}