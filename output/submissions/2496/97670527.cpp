#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    ll x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, M, T, K;
    cin >> N >> M >> T >> K;
    vector<Point> diamonds(T);
    for (int i = 0; i < T; ++i) {
        cin >> diamonds[i].x >> diamonds[i].y;
    }
    
    ll max_count = 0;
    ll best_x = 0, best_y = 0;
    
    vector<ll> u(T), v(T);
    for (int i = 0; i < T; ++i) {
        u[i] = diamonds[i].x + diamonds[i].y;
        v[i] = diamonds[i].x - diamonds[i].y;
    }
    
    for (int i = 0; i < T; ++i) {
        for (int j = i; j < T; ++j) {
            vector<ll> us = { max(u[i], u[j]) - K/2, min(u[i], u[j]) + K/2 };
            vector<ll> vs = { max(v[i], v[j]) - K/2, min(v[i], v[j]) + K/2 };
            
            for (ll U : us) {
                for (ll V : vs) {
                    ll X = (U + V) / 2;
                    ll Y = (U - V) / 2;
                    
                    if ((U + V) % 2 != 0 || (U - V) % 2 != 0) continue;
                    if (X < 0 || X > N || Y < 0 || Y > M) continue;
                    
                    ll count = 0;
                    for (int k = 0; k < T; ++k) {
                        if (abs(diamonds[k].x - X) + abs(diamonds[k].y - Y) <= K/2) {
                            ++count;
                        }
                    }
                    
                    if (count > max_count) {
                        max_count = count;
                        best_x = X;
                        best_y = Y;
                    }
                }
            }
        }
    }
    
    cout << best_x << " " << best_y << "\n" << max_count << "\n";
    
    return 0;
}