#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, T, K;
    if (!(cin >> N >> M >> T >> K)) return 0;

    vector<pair<ll,ll>> pts(T);
    for (int i = 0; i < T; ++i) {
        ll x, y; cin >> x >> y;
        pts[i] = {x, y};
    }

    vector<pair<ll,ll>> uv(T);
    for (int i = 0; i < T; ++i) {
        ll x = pts[i].first, y = pts[i].second;
        uv[i] = {x + y, x - y};
    }

    const ll half = K / 2;
    auto inside_count = [&](ll U, ll V) {
        int c = 0;
        for (int i = 0; i < T; ++i) {
            ll du = llabs(uv[i].first  - U);
            ll dv = llabs(uv[i].second - V);
            if (du <= half && dv <= half) ++c;
        }
        return c;
    };

    ll bestX = 0, bestY = 0;
    int bestC = -1;

    for (int i = 0; i < T; ++i) {
        for (int j = 0; j < T; ++j) {
            for (int su = -1; su <= 1; su += 2) {
                for (int sv = -1; sv <= 1; sv += 2) {
                    ll U = uv[i].first  + su * half;
                    ll V = uv[j].second + sv * half;
                    if (((U ^ V) & 1LL)) continue;
                    ll X = (U + V) / 2;
                    ll Y = (U - V) / 2;
                    if (X < 0 || X > N || Y < 0 || Y > M) continue;
                    int c = inside_count(U, V);
                    if (c > bestC) {
                        bestC = c;
                        bestX = X;
                        bestY = Y;
                    }
                }
            }
        }
    }

    cout << bestX << ' ' << bestY << '\n';
    cout << bestC << '\n';
    return 0;
}