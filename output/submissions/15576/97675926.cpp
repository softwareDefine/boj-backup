#define r first
#define i second
#include <math.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <vector>
#include <iostream>

using ll = long long;
using namespace std;
using complex = pair<double, double>;
const double pi = acos(-1);

complex operator+(complex a, complex b) {
    return {a.r + b.r, a.i + b.i};
}
complex operator-(complex a, complex b) {
    return {a.r - b.r, a.i - b.i};
}
complex operator*(complex a, complex b) {
    return {a.r * b.r - a.i * b.i, a.r * b.i + b.r * a.i};
}

void fft(vector<complex> &a, ll n, bool invert) {
    for (ll i = 1, j = 0; i < n; i++) {
        ll bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (ll len = 2; len <= n; len <<= 1) {
        double ang = 2 * pi / len * (invert ? -1 : 1);
        complex wlen = {cos(ang), sin(ang)};
        for (ll i = 0; i < n; i += len) {
            complex w = {1.0, 0.0};
            for (ll j = 0; j < len / 2; j++) {
                complex u = a[i + j];
                complex v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w = w * wlen;
            }
        }
    }
}

void multpol(vector<complex> &a, vector<complex> &b, vector<complex> &c, ll n) {
    fft(a, n, false);
    fft(b, n, false);
    for (ll i = 0; i < n; i++) c[i] = a[i] * b[i];
    fft(c, n, true);
    for (ll i = 0; i < n; i++) {
        c[i].r /= n;
        c[i].i /= n;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    complex zero = {0.0, 0.0};
    string a, b;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    ll alen = (ll)a.size();
    ll blen = (ll)b.size();

    ll need = alen + blen + 1;
    ll n = 1;
    while (n < need) n <<= 1;

    vector<complex> A(n, zero), B(n, zero), C(n, zero);

    for (ll i = 0; i < alen; i++) A[i].r = (a[i] - '0');
    for (ll i = 0; i < blen; i++) B[i].r = (b[i] - '0');

    multpol(A, B, C, n);

    for (ll i = 0; i < alen + blen; i++) {
        long long val = llround(C[i].r);
        if (val < 0) { 
            long long borrow = (-(val) + 9) / 10;
            C[i + 1].r -= borrow;
            val += borrow * 10;
        }
        C[i].r = val % 10;
        C[i + 1].r += val / 10;
    }

    ll idx = alen + blen;
    while (idx > 0 && llround(C[idx].r) == 0) idx--;

    for (ll i = idx; i >= 0; i--) cout << (long long)llround(C[i].r);
    return 0;
}
