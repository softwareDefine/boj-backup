#include <bits/stdc++.h>
using namespace std;

struct Line {
    pair<int,int> p, q;   // 두 끝점
};

int n;
vector<Line> seg;
vector<int> deg;          // 각 선분이 교차하는 개수

/* ── 0~204 까지의 둘레 좌표로 변환 ───────────────────────────
   (x ,y)
   ┌───────────────51───────────────┐
   │                               ▲│ y=0 (윗변)
 0 │ → x                            │
   │                               │
   │                (51, y)        │
51 │ → y                           │  오른쪽변
   │                               ▼
   │                               │
102│ ← (x,51)                      │  아랫변
   │                               │
   │ (0,y)                         │
153│ ← (0, 51-y)                   │  왼쪽변
   └───────────────────────────────┘
*/
int perimeterVal (pair<int,int> pt) {
    int x = pt.first, y = pt.second;
    if (y == 0)          return x;               // top 0~51
    if (x == 51)         return 51 + y;          // right 51~102
    if (y == 51)         return 102 + (51 - x);  // bottom 102~153
    /* x == 0 */         return 153 + (51 - y);  // left 153~204
}

bool isCross (const Line& A, const Line& B) {
    int a1 = perimeterVal(A.p), a2 = perimeterVal(A.q);
    int b1 = perimeterVal(B.p), b2 = perimeterVal(B.q);

    if (a1 > a2) swap(a1, a2);   // a1 < a2
    if (b1 > b2) swap(b1, b2);   // b1 < b2

    // *** 교차 조건: 끝점이 번갈아 등장 ***
    // a1 < b1 < a2 < b2  OR  b1 < a1 < b2 < a2
    return (a1 < b1 && b1 < a2 && a2 < b2) ||
           (b1 < a1 && a1 < b2 && b2 < a2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;                   // 주어지는 점의 개수 (짝수)
    int m = n / 2;              // 선분 수
    seg.reserve(m);
    deg.assign(m, 0);

    for (int i = 0; i < m; ++i) {
        int a,b,c,d;            // (변 번호, 거리)
        cin >> a >> b >> c >> d;

        auto convert = [](int edge, int dist)
        {
            if (edge == 3) return make_pair(0 , dist);       // 왼쪽
            if (edge == 4) return make_pair(51, dist);       // 오른쪽
            if (edge == 2) return make_pair(dist, 51);       // 아래
            /* edge == 1 */  return make_pair(dist, 0 );     // 위
        };
        seg.push_back({convert(a,b), convert(c,d)});
    }

    long long total = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i+1; j < m; ++j) {
            if (isCross(seg[i], seg[j])) {
                ++deg[i]; ++deg[j];
                ++total;              // 서로 다른 두 선만 세므로 바로 +=1
            }
        }
    }

    int mx = *max_element(deg.begin(), deg.end());
    cout << total << '\n' << mx << '\n';
    return 0;
}
