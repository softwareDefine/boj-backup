#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;
using i128 = __int128_t;  
using u128 = __uint128_t;

u64 arrv[70];

string to_binary_min(u64 x) {
    if (x == 0) return "0";
    string s = bitset<64>(x).to_string();
    auto pos = s.find('1');
    return s.substr(pos);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 64; ++i) {
        arrv[i] = (u64)(i + 1) * ( (u64)1 << i );
    }

    u64 a, b;
    cin >> a >> b;
    u64 a1 = a - 1;

    string atr = to_binary_min(a1);
    string btr = to_binary_min(b);

    u128 ans = 0;

    {
        u64 total = 0;
        int len = (int)btr.size();
        for (int i = 0; i < len; ++i) {
            if (btr[i] == '1') {
                if (i != len - 1) {
                    int k = len - i - 2;         
                    int p = len - i - 1;          
                    ans += (u128)arrv[k];
                    ans += (u128)total * ((u64)1 << p);  
                } else {
                    ans += (u128)total;
                }
                ++total;
            }
        }
        ans += (u128)total;
    }

    {
        u64 total = 0;
        int len = (int)atr.size();
        for (int i = 0; i < len; ++i) {
            if (atr[i] == '1') {
                if (i != len - 1) {
                    int k = len - i - 2;
                    int p = len - i - 1;
                    ans -= (u128)arrv[k];
                    ans -= (u128)total * ((u64)1 << p);
                } else {
                    ans -= (u128)total;
                }
                ++total;
            }
        }
        ans -= (u128)total;
    }

    if (ans == 0) { cout << 0 << '\n'; return 0; }
    string out;
    while (ans > 0) {
        int d = (int)(ans % 10);
        out.push_back('0' + d);
        ans /= 10;
    }
    reverse(out.begin(), out.end());
    cout << out << '\n';
}
