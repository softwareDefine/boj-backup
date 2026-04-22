#include<bits/stdc++.h>

using ll = long long;
using namespace std;

int t;
ll arr[1100000];

int main(){
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        ll mmx = 0;
        ll sum = 0;
        for(int i=n-1;i>=0;i--){
            mmx = max(mmx,arr[i]);
            sum += mmx-arr[i];
        }
        cout << sum << '\n';
    }
}