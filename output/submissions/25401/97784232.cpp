#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int n;
ll arr[1000];
ll mmn = 9999999999999;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll quo = (arr[j]-arr[i])/(j-i);
            if((arr[j]-arr[i])%(j-i) != 0){
                continue;
            }
            ll cnt = 0;
            for(int k=0;k<n;k++){
                if(arr[i] + (k-i)*quo != arr[k]){
                    cnt++;
                }
            }
            mmn = min(mmn,cnt);
        }
    }
    cout << mmn;
}