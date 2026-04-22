#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;

vector<pair<lint,lint>> vc(n+1);
lint dp[20000];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    fill(dp,dp+20000,999999999999);
    cin >> n;
    for(int i=1;i<=n;i++){
        lint x,y;
        cin >> x >> y;
        vc.insert(vc.begin() + i, {x,y});
    }
    sort(vc.begin() + 1,vc.end(),[](auto a,auto b){
        if(a.first == b.first) return abs(a.second) < abs(b.second);
        return a.first < b.first;
    });
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        lint mmx = 0;
        for(int j=i;j<=n;j++){
            mmx = max(mmx,abs(vc[j].second)*2);
            dp[j] = min(dp[j],dp[i-1]+max(mmx,vc[j].first-vc[i].first));
        }
    }
    cout << dp[n];
}