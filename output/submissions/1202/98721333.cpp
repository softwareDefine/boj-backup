#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n,k;

pair<lint,lint> jew[400000];
set<lint> st;

lint ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> jew[i].first >> jew[i].second;
    }
    for(int i=0;i<k;i++){
        lint pack;
        cin >> pack;
        st.insert(pack);
    }
    sort(jew,jew+n,[](auto a,auto b){
        if(a.second == b.second){return a.first < b.first;}
        return a.second > b.second;
    });
    for(int i=0;i<n;i++){
        lint weight = jew[i].first;
        lint price = jew[i].second;
        auto it = st.lower_bound(weight);
        if(it == st.end()){
            continue;
        }else{
            ans += price;
            st.erase(*it);
        }
    }
    cout << ans;
}