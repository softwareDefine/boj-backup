#include <iostream>
#include <deque>
#include <vector>


using ll = long long;
using namespace std;

ll n, m, c;
ll arr[2000010];
// 값,idx
vector<ll> ans;
deque<pair<ll,ll>> mmx;
deque<pair<ll,ll>> mmn;

int main()
{
    cin >> n >> m >> c;
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (ll i = 1; i <= n; i++) {
        if (!mmx.empty() && mmx.front().second == i-m) {
            mmx.pop_front();
        }
        if (!mmn.empty() && mmn.front().second == i-m) {
            mmn.pop_front();
        }
        while (!mmx.empty() && mmx.back().first < arr[i]) {
            mmx.pop_back();
        }
        while (!mmn.empty() && mmn.back().first > arr[i]) {
            mmn.pop_back();
        }
        mmx.push_back({ arr[i],i });
        mmn.push_back({ arr[i],i });
        if (mmx.front().first - mmn.front().first <= c) {
            if (i - m + 1 >= 1) {
                ans.push_back(i - m + 1);
            }
        }
    }
    if (ans.empty()) {
        cout << "NONE";
    }
    else {
        for (auto& i : ans) {
            cout << i << '\n';
        }
    }
}