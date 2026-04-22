#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll k,n;
ll c;
ll arr[12000];
ll mmxsum;
int flag = 0;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> k >> n;
    cin >> c;
    for(int i=0;i<k;i++){
        cin >> arr[i];
    }
    sort(arr,arr+k);
    for(int i=k-1;i>max(k-1-n,-1LL);i--){
        mmxsum += arr[i];
    }
    ll mysum = 0;
    ll theifsum = 0;
    ll next = 0;
    for(int i=0;i<n;i++){
        theifsum += arr[i];
    }
    for(int i=1;i<=c;i++){
        if(mysum + arr[next] <= i && !flag){
            mysum += arr[next];
            theifsum -= arr[next];
            theifsum += arr[next+n];
            if(!arr[next+n]){
                flag = 1;
                theifsum = mmxsum;
            }
            next++;
        }
        cout << theifsum << '\n';
    }
}