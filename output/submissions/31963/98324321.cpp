#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;
lint arr[300000];
lint cnt;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=1;i<n;i++){
        while(arr[i-1] > arr[i]){
            arr[i] *= 2;
            cnt++;
        }
    }
    cout << cnt;
}