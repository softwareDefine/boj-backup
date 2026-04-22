#define x first
#define y second
#define LLONG_MAX 9223372036854775807
#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using ll = long long;
using namespace std;
using point = pair<ll, ll>;

inline ll square(ll v) {
    return v * v;
}
inline ll dist(point p1,point p2) {
    return square(p2.x - p1.x) + square(p2.y - p1.y);
}
struct comparey {
    bool operator () (point p1, point p2) {
        return tie(p1.y,p1.x) < tie(p2.y,p2.x);
    }
};

int n;
point a[101010], b[101010];

ll DnC(int l, int r) {
    if (l == r) {
        return LLONG_MAX;
    }
    int m = (l + r) / 2;
    ll xm = a[m].x, d = min(DnC(l,m),DnC(m+1,r));
    merge(a + l, a + m + 1, a + m + 1, a + r + 1, b + l, comparey());
    copy(b + l, b + r + 1, a + l);

    vector<point> p;
    for (int i = l; i <= r; i++) {
        if (square(a[i].x - xm) < d) {
            p.push_back(a[i]);
        }
    }
    for (int i = 0; i < p.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (square(p[i].y - p[j].y) < d) {
                d = min(d, dist(p[i],p[j]));
            }
            else {
                break;
            }
        }
    }
    return d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a+1, a + n+1);
    cout << DnC(1,n);
}