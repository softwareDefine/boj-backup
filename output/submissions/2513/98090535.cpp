#include <bits/stdc++.h>

using namespace std;

int n,k,s;
vector<pair<int,int>> vc;

int main(){
    cin >> n >> k >> s;
    for(int i=0;i<n;i++){
        int x,c;
        cin >> x >> c;
        vc.push_back({x,c});
    }
    sort(vc.begin(),vc.end());
    int ans = 0;
    int last = 0;
    for(auto [now,cost] : vc){
        if(s > now){
            if(last > 0){
                if(last - cost < 0){
                    cost -= last;
                    last = 0;
                }else{
                    last -= cost;
                    continue;
                }
            }
            if(cost%k){
                    ans += ((cost-1)/k+1)*abs(now-s)*2;
                    last = k - cost%k;
                }else{
                    ans += ((cost-1)/k+1)*abs(now-s)*2;
                }   
        }else{
            break;
        }
    }
    reverse(vc.begin(),vc.end());
    last = 0;
    for(auto [now,cost] : vc){
        if(s < now){
            if(last > 0){
                if(last - cost < 0){
                    cost -= last;
                    last = 0;
                }else{
                    last -= cost;
                    continue;
                }
            }
            if(cost%k){
                    ans += ((cost-1)/k+1)*abs(now-s)*2;
                    last = k - cost%k;
            }else{
                    ans += ((cost-1)/k+1)*abs(now-s)*2;
            }   
        }else{
            break;
        }
    }
    cout << ans;
}