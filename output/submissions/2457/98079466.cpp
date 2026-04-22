#include <bits/stdc++.h>

using namespace std;

int n;
map<int,int> mp;
vector<pair<int,int>> vc;
int visited[500];
int dp[500];
int mmn =999999999;

int main(){
    for(int i=0;i<500;i++){dp[i] = 999999999;}
    cin >> n;
    for(int i=0;i<n;i++){
        int sm,sd;
        int em,ed;
        cin >> sm >> sd >> em >> ed;
        if(mp.find(sm*100+sd) != mp.end()){
            mp[sm*100+sd] = max(mp[sm*100+sd],em*100+ed);
        }else{
            mp[sm*100+sd] = em*100+ed;
        }
    }
    for(auto [start,end] : mp){
        vc.push_back({start,end});
    }
    //dp[0] = 1;
    for(int i=0;i<vc.size();i++){
        //cout << vc[i].first << ' ' << vc[i].second << '\n';
        for(int j=i+1;j<vc.size();j++){
            if(vc[i].second >= vc[j].first){
                if(vc[i].first <= 301){
                    dp[j] = min(dp[j],2);
                }
                dp[j] = min(dp[j],dp[i]+1);
            }
        }
    }
    for(int i=0;i<vc.size();i++){
        if(vc[i].first <= 301 && vc[i].second > 1130){
            mmn = 1;
        }
        if(vc[i].second > 1130){
            mmn = min(mmn,dp[i]);
        }
    }
    if(mmn == 999999999){
        cout << 0;
    }else{
        cout << mmn;
    }
}