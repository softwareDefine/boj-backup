#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n;

lint arr[5000];
lint brr[5000];
lint crr[5000];
lint drr[5000];

vector<lint> vc;
vector<lint> vc2;

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
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vc2.push_back(crr[i]+drr[j]);
        }
    }
    sort(vc.begin(),vc.end());
    sort(vc2.begin(),vc2.end());
    for(auto element : vc){
        ans += upper_bound(vc2.begin(),vc2.end(),-element) - lower_bound(vc2.begin(),vc2.end(),-element);
    }
    cout << ans;
}