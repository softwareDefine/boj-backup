#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>

using namespace std;

int n;
int all;
int uinf = -1000000000;

pair<int, int> len = {uinf,uinf};

vector<pair<int, int>> vc;

int cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vc.push_back({ a,b });
    }
    stable_sort(vc.begin(), vc.end(), cmp);
    for (int i = 0; i < n; i++) {
        // 새출발 지점
        if (len.second < vc[i].first) {
            all += len.second - len.first;
            len.first = vc[i].first;
        }
        // 기존 연장 경우
        if (vc[i].second > len.second ) {
            len.second = vc[i].second;
        }
    }
    all += len.second - len.first;
    cout << all << '\n';
}