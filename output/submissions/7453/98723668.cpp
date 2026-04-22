#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n;

lint arr[5000];
lint brr[5000];
lint crr[5000];
lint drr[5000];

vector<lint> vc;
map<lint,int> mp2;

int ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i] >> brr[i] >> crr[i] >> drr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vc.push_back(arr[i]+brr[j]);
        }
    }
    sort(vc.begin(),vc.end());
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mp2[crr[i]+drr[j]]++;
        }
    }
    for(auto element : vc){
        ans += mp2[-element];
    }
    cout << ans;
}