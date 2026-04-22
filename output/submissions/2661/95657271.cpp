#include <bits/stdc++.h>
using namespace std;

int n;
string s;

bool isBad(int len, int k) {
    for (int i = 0; i < k; i++) {
        if (s[len - i] != s[len - k - i])
            return false;
    }
    return true;
}

bool go(int len) {
    if (len == n) {
        cout << s << "\n";
        return true;  // 성공 시 바로 종료
    }
    for (char c = '1'; c <= '3'; c++) {
        s[len] = c;
        bool bad = false;

        for (int k = 1; k * 2 <= len + 1; k++) {
            if (isBad(len, k)) {
                bad = true;
                break;
            }
        }
        if (!bad) {
            if (go(len + 1))
                return true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    s.resize(n);
    cout << go(0);
    return 0;
}
