#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N,M,T,K; 
    if(!(cin>>N>>M>>T>>K)) return 0;
    vector<pair<ll,ll>> pts(T);
    for(int i=0;i<T;i++) cin>>pts[i].first>>pts[i].second;

    vector<pair<ll,ll>> uv(T);
    for(int i=0;i<T;i++){
        ll x=pts[i].first, y=pts[i].second;
        uv[i]={x+y, x-y};
    }

    ll half=K/2;
    vector<ll> Uc, Vc;
    Uc.reserve(2*T); Vc.reserve(2*T);
    for(int i=0;i<T;i++){
        ll u=uv[i].first, v=uv[i].second;
        ll lU=max(0LL, u-half), rU=min(N+M, u+half);
        ll lV=max(-M, v-half), rV=min(N, v+half);
        Uc.push_back(lU); Uc.push_back(rU);
        Vc.push_back(lV); Vc.push_back(rV);
    }
    sort(Uc.begin(), Uc.end()); Uc.erase(unique(Uc.begin(), Uc.end()), Uc.end());
    sort(Vc.begin(), Vc.end()); Vc.erase(unique(Vc.begin(), Vc.end()), Vc.end());

    ll bestX=0, bestY=0; int bestC=-1;
    for(ll U: Uc){
        for(ll V: Vc){
            if(((U^V)&1LL)) continue;
            ll X=(U+V)/2, Y=(U-V)/2;
            if(X<0||X>N||Y<0||Y>M) continue;
            int c=0;
            for(int i=0;i<T;i++){
                if(llabs(uv[i].first-U)<=half && llabs(uv[i].second-V)<=half) ++c;
            }
            if(c>bestC){
                bestC=c; bestX=X; bestY=Y;
            }
        }
    }

    cout<<bestX<<' '<<bestY<<'\n'<<bestC<<'\n';
    return 0;
}
