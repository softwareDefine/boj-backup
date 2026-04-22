#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n;
vector<int> vc;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j< n;j++){
            int element;
            cin >> element;
            vc.push_back(element);
        }
    }
    sort(vc.begin(), vc.end());
    cout << vc[n-1];
}