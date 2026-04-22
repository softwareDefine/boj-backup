#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, M, T, K;
    cin >> N >> M >> T >> K;

    vector<pll> diamonds;
    vector<ll> u_list, v_list;

    for (int i = 0; i < T; i++) {
        ll x, y;
        cin >> x >> y;
        diamonds.push_back({x, y});
        ll u = x + y;
        ll v = y - x;
        u_list.push_back(u);
        v_list.push_back(v);
    }

    sort(u_list.begin(), u_list.end());
    sort(v_list.begin(), v_list.end());

    ll best_count = -1;
    ll best_x = 0, best_y = 0;

    for (ll u_candidate : u_list) {
        for (ll v_candidate : v_list) {
            ll u_min = u_candidate;
            ll u_max = u_candidate + K;
            ll v_min = v_candidate;
            ll v_max = v_candidate + K;

            ll count = 0;
            for (auto& diamond : diamonds) {
                ll x = diamond.first;
                ll y = diamond.second;
                ll u = x + y;
                ll v = y - x;
                if (u >= u_min && u <= u_max && v >= v_min && v <= v_max) {
                    count++;
                }
            }

            if (count > best_count) {
                best_count = count;
                ll x_center = (u_min + u_max - K) / 2;
                ll y_center = (v_min + v_max + K) / 2;
                x_center = max(0LL, min(N, x_center));
                y_center = max(0LL, min(M, y_center));
                best_x = x_center;
                best_y = y_center;
            }
        }
    }

    cout << best_x << " " << best_y << "\n";
    cout << best_count << "\n";

    return 0;
}