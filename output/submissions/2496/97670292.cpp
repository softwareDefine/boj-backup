#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, T, K;
    if(!(cin >> N >> M >> T >> K)) return 0;
    vector<pair<ll,ll>> a(T);
    for(int i=0;i<T;i++) cin >> a[i].first >> a[i].second;

    ll R = K/2;

    vector<pair<ll,ll>> cand;
    cand.reserve(4*T*T + T + 4);

    for(int i=0;i<T;i++){
        ll Si1 = a[i].first + a[i].second + R;
        ll Si2 = a[i].first + a[i].second - R;
        for(int j=0;j<T;j++){
            ll Dj1 = a[j].first - a[j].second + R;
            ll Dj2 = a[j].first - a[j].second - R;
            ll S[2] = {Si1, Si2};
            ll D[2] = {Dj1, Dj2};
            for(int s=0;s<2;s++){
                for(int d=0;d<2;d++){
                    ll Sval = S[s], Dval = D[d];
                    if(((Sval ^ Dval) & 1LL)) continue;
                    ll X = (Sval + Dval) / 2;
                    ll Y = (Sval - Dval) / 2;
                    if(0 <= X && X <= N && 0 <= Y && Y <= M) cand.push_back({X,Y});
                }
            }
        }
    }

    for(int i=0;i<T;i++) cand.push_back(a[i]);
    cand.push_back({0,0});
    cand.push_back({0,M});
    cand.push_back({N,0});
    cand.push_back({N,M});

    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());

    auto count_in = [&](ll X, ll Y){
        int c = 0;
        for(int i=0;i<T;i++){
            ll dx = llabs(a[i].first  - X);
            ll dy = llabs(a[i].second - Y);
            if(dx + dy <= R) ++c;
        }
        return c;
    };

    ll bestX = 0, bestY = 0;
    int bestC = -1;

    for(auto &p : cand){
        ll X = p.first, Y = p.second;
        int c = count_in(X, Y);
        if(c > bestC){
            bestC = c;
            bestX = X;
            bestY = Y;
        }
    }

    cout << bestX << ' ' << bestY << '\n' << bestC << '\n';
    return 0;
}
