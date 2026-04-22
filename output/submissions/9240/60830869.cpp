#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define x first
#define y second
using namespace std;
using ll = long long;
using point = pair<ll, ll>;
vector<point> vc;
point zero = { 0,0 };
int n;
inline int ccw(point a, point b, point c) { ll res = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);return (res > 0) - (res < 0); }
inline ll dist(point a, point b) { return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); }
point operator- (point a, point b) {
    return { a.x - b.x ,a.y - b.y };
}
int chk(point a, point b, point c, point d) {
    point xx = b - a;
    point yy = d - c;
    return ccw(zero, xx, yy) >= 0;
}
vector<point> convexhull(vector<point>& vc) {
    swap(vc[0], *min_element(vc.begin(), vc.end()));
    sort(vc.begin() + 1, vc.end(), [&](auto a, auto b) {int dir = ccw(vc[0], a, b);
        if (dir == 0) { return dist(vc[0], b) < dist(vc[0], b); }
        return dir > 0;
    });
    vector<point> con;
    for (auto& i : vc) {
        while (con.size() >= 2 && ccw(con[con.size() - 2], con.back(), i) <= 0) { con.pop_back(); }
        con.push_back(i);
    }
    return con;
}
ll rotating(vector<point>& vc) {
    vector<point> con = convexhull(vc);
    int j = 0;
    ll mmx = 0;
    for (int i = 0;i < con.size();i++) {
        while (j + 1 < con.size() && chk(con[i], con[i + 1], con[j], con[j + 1])) { mmx = max(dist(con[i], con[j]), mmx);j++; }
        mmx = max(dist(con[i], con[j]), mmx);
    }
    return mmx;
}
int main()
{
    cin >> n;
    for (int i = 0;i < n;i++) {
        ll px, py;
        cin >> px >> py;
        vc.push_back(make_pair(px, py));
    }
    printf("%.8lf",sqrt(rotating(vc)));
}