#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    ll N, M, T, K;

    if (!(cin >> N >> M >> T >> K)) return 0;

    ll R = K / 2; // 다이아 반경 (맨해튼)

    struct P { ll x, y; };

    vector<P> pts(T);

    for (int i = 0; i < T; ++i) cin >> pts[i].x >> pts[i].y;

    // 후보 U = X+Y, V = X-Y 값들 수집

    vector<ll> Ucand, Vcand;

    Ucand.push_back(0);

    Ucand.push_back(N + M);

    Vcand.push_back(-M);

    Vcand.push_back(N);

    for (auto &p : pts) {

        ll a = p.x + p.y; // X+Y 경계 후보

        ll b = p.x - p.y; // X-Y 경계 후보

        Ucand.push_back(a - R);

        Ucand.push_back(a + R);

        Vcand.push_back(b - R);

        Vcand.push_back(b + R);

    }

    sort(Ucand.begin(), Ucand.end());

    Ucand.erase(unique(Ucand.begin(), Ucand.end()), Ucand.end());

    sort(Vcand.begin(), Vcand.end());

    Vcand.erase(unique(Vcand.begin(), Vcand.end()), Vcand.end());

    auto inMap = [&](ll X, ll Y) {

        return (0 <= X && X <= N && 0 <= Y && Y <= M);

    };

    ll bestCnt = -1, bestX = 0, bestY = 0;

    for (ll U : Ucand) {

        if (U < 0 || U > N + M) continue; // 지도 내 가능한 U 범위

        for (ll V : Vcand) {

            if (V < -M || V > N) continue; // 지도 내 가능한 V 범위

            if ( ( (U ^ V) & 1LL ) ) continue; // U와 V의 짝/홀수 일치 필요

            ll X = (U + V) / 2;

            ll Y = (U - V) / 2;

            if (!inMap(X, Y)) continue;

            // 포함 개수 계산 (경계 포함)

            ll cnt = 0;

            for (auto &p : pts) {

                ll d = llabs(p.x - X) + llabs(p.y - Y);

                if (d <= R) ++cnt;

            }

            if (cnt > bestCnt || (cnt == bestCnt && (X < bestX || (X == bestX && Y < bestY)))) {

                bestCnt = cnt;

                bestX = X;

                bestY = Y;

            }

        }

    }

    cout << bestX << ' ' << bestY << '\n' << bestCnt << '\n';

    return 0;

}