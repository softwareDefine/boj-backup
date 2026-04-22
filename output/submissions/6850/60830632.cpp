#define x first
#define y second
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

using point = pair<long long, long long>;

vector<point> vc;

int n;

int ccw(point a,point b,point c) {
    long long res = a.x * b.y + b.x * c.y + c.x * a.y;
    res -= a.y * b.x + b.y * c.x + c.y * a.x;
    return (res > 0) - (res < 0);
}

long long dist(point a, point b) {
    return pow(b.x - a.x, 2) + pow(b.y - a.y, 2);
}

vector<point> block(vector<point> &points) {
    swap(points[0], *min_element(points.begin(),points.end()));
    sort(points.begin() + 1, points.end(), [&](point a, point b) {
        int check = ccw(points[0], a, b);
        if (check != 0) {
            return check > 0;
        }
        else {
            return dist(points[0], a) < dist(points[0], b);
        }
    });
    vector<point> st;
    for (auto i : points) {
        while (st.size() >= 2 && ccw(st[st.size() - 2], st.back(), i) <= 0) {
            st.pop_back();
        }
        st.push_back(i);
    }
    return st;
}

long long value(vector<point> get = block(vc)) {
    if (get.size() <= 2) {
        cout << 0;
    }else{
        long long sum = 0;
        long long n = get.size();
        for (int i = 0; i < n; i++) {
            int j = (i + 1 == n) ? 0 : i + 1;
            sum += get[i].x * get[j].y;
        }
        for (int i = 0; i < n; i++) {
            int j = (i + 1 == n) ? 0 : i + 1;
            sum -= get[i].y * get[j].x;
        }
        return abs(sum)/100;
    }
}

int main()
{
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        vc.push_back({ a,b });
    }
    cout << value();
}