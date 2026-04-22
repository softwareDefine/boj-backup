#include <bits/stdc++.h>
using lint = long long;
using namespace std;

lint n, p1, p3, p5, ppair;
string a, b;
lint arr[2001], brr[2001];
lint dp[2001][2001];

lint go(int korea, int koi) {
    // If both schedules are done, return 0
    if (korea >= n && koi >= n) return 0;
    // If one schedule is done, process the other
    if (korea >= n) {
        if (brr[koi] == 0) return go(korea, koi + 1); // No ticket needed
        return min(p1 + go(korea, koi + 1), min(p3 + go(korea, koi + 3), p5 + go(korea, koi + 5)));
    }
    if (koi >= n) {
        if (arr[korea] == 0) return go(korea + 1, koi); // No ticket needed
        return min(p1 + go(korea + 1, koi), min(p3 + go(korea + 3, koi), p5 + go(korea + 5, koi)));
    }
    
    // If already computed, return cached result
    if (dp[korea][koi] != -1) return dp[korea][koi];
    
    lint ans = LLONG_MAX;
    
    // Skip if no one needs a ticket
    if (arr[korea] == 0 && brr[koi] == 0) {
        ans = min(ans, go(korea + 1, koi + 1));
    }
    
    // 1-day tickets for each person
    if (arr[korea] == 1 && brr[koi] == 1) {
        ans = min(ans, p1 + p1 + go(korea + 1, koi + 1)); // Both buy 1-day
    }
    if (arr[korea] == 1) {
        ans = min(ans, p1 + go(korea + 1, koi)); // Korea buys 1-day
    }
    if (brr[koi] == 1) {
        ans = min(ans, p1 + go(korea, koi + 1)); // Koi buys 1-day
    }
    
    // 3-day ticket for Korea
    if (arr[korea] == 1) {
        ans = min(ans, p3 + go(korea + 3, koi));
    }
    // 3-day ticket for Koi
    if (brr[koi] == 1) {
        ans = min(ans, p3 + go(korea, koi + 3));
    }
    
    // 5-day ticket for Korea
    if (arr[korea] == 1) {
        ans = min(ans, p5 + go(korea + 5, koi));
    }
    // 5-day ticket for Koi
    if (brr[koi] == 1) {
        ans = min(ans, p5 + go(korea, koi + 5));
    }
    
    // Pair ticket for both
    if (arr[korea] == 1 || brr[koi] == 1) {
        ans = min(ans, ppair + go(korea + 4, koi + 4));
    }
    
    return dp[korea][koi] = ans;
}

int main() {
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        arr[i] = a[i] - '0';
        brr[i] = b[i] - '0';
    }
    cin >> p1 >> p3 >> p5 >> ppair;
    
    // Initialize DP array
    memset(dp, -1, sizeof(dp));
    
    cout << go(0, 0) << endl;
    return 0;
}