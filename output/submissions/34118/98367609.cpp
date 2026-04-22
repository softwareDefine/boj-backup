#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = (lint)4e18;

lint n;
string a, b;
lint arr[9000], brr[9000];
lint p1, p3, p5, ppair;
lint dp[9000][9000];

lint go(int korea, int koi) {
    if (korea >= n && koi >= n) return 0;
    lint &ret = dp[korea][koi];
    if (ret != INF) return ret;
    ret = INF;

    // 한쪽이 끝났으면, 남은 한쪽만 처리 (정확 전진)
    if (korea >= n) {
        // koi만 남음
        // 1일권
        ret = min(ret, go(korea, koi+1) + (koi < n ? brr[koi]*p1 : 0));
        // 3일권
        ret = min(ret, go(korea, koi+3) + p3);
        // 5일권
        ret = min(ret, go(korea, koi+5) + p5);
        return ret;
    }
    if (koi >= n) {
        // korea만 남음
        // 1일권
        ret = min(ret, go(korea+1, koi) + (korea < n ? arr[korea]*p1 : 0));
        // 3일권
        ret = min(ret, go(korea+3, koi) + p3);
        // 5일권
        ret = min(ret, go(korea+5, koi) + p5);
        return ret;
    }

    // 둘 다 남아있음 — 정확 전진만 허용
    // 1+1
    ret = min(ret, go(korea+1, koi+1) + arr[korea]*p1 + brr[koi]*p1);

    // 1+(3|5)
    ret = min(ret, go(korea+1, koi+3) + arr[korea]*p1 + p3);
    ret = min(ret, go(korea+1, koi+5) + arr[korea]*p1 + p5);

    // (3|5)+1
    ret = min(ret, go(korea+3, koi+1) + p3 + brr[koi]*p1);
    ret = min(ret, go(korea+5, koi+1) + p5 + brr[koi]*p1);

    // 3+(3|5), 5+(3|5)
    ret = min(ret, go(korea+3, koi+3) + p3 + p3);
    ret = min(ret, go(korea+3, koi+5) + p3 + p5);
    ret = min(ret, go(korea+5, koi+3) + p5 + p3);
    ret = min(ret, go(korea+5, koi+5) + p5 + p5);

    // 묶음권: 같은 날 시작일 때만 정확히 4/4
    if (korea == koi) {
        ret = min(ret, go(korea+4, koi+4) + ppair);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // dp 초기화
    for (int i = 0; i < 9000; ++i)
        for (int j = 0; j < 9000; ++j)
            dp[i][j] = INF;

    cin >> n;
    cin >> a;
    cin >> b;

    for (int i = 0; i < n; i++) arr[i] = a[i]-'0';
    for (int i = 0; i < n; i++) brr[i] = b[i]-'0';

    cin >> p1 >> p3 >> p5 >> ppair;

    cout << go(0, 0);
    return 0;
}
