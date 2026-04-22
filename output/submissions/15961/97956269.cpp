#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll n,d,k,c;
ll arr[4100000];
ll now[3100];
ll mmx;

int main(){
    cin >> n >> d >> k >> c;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        arr[i+n] = arr[i];
    }
    ll sum = k+1;
    now[c] = 1;
    for(int j=0;j<k;j++){
        if(now[arr[j]]){
            sum -= 1;
        }
        now[arr[j]]++;
    }
    mmx = max(mmx,sum);
    for(int i=k;i<n+k+1;i++){
        if(!now[arr[i]]){
            sum += 1;
        }
        now[arr[i]]++;
        now[arr[i-k]]--;
        if(!now[arr[i-k]]){
            sum -= 1;
        }
        mmx = max(mmx,sum);
    }
    cout << mmx;
}