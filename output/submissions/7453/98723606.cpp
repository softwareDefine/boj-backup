#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n;

lint arr[5000];
lint brr[5000];
lint crr[5000];
lint drr[5000];

map<lint,int> mp1;
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
            mp1[arr[i]+brr[j]]++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mp2[crr[i]+drr[j]]++;
        }
    }
    for(auto i=mp1.begin();i!=mp1.end();i++){
        lint cnt = 0;
        if(mp2.find(-((*i).first)) != mp2.end()){
            cnt = mp2[-((*i).first)];
        }
        ans += cnt*((*i).second);
    }
    cout << ans;
}