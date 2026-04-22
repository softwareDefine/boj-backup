#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int n, m, c;
int arr[1000010];
// 값,idx
vector<int> ans;
deque<pair<int,int>> mmx;
deque<pair<int,int>> mmn;

int main()
{
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        if (!mmx.empty() && mmx.front().second == i-m) {
            mmx.pop_front();
        }
        if (!mmn.empty() && mmn.front().second == i-m) {
            mmn.pop_front();
        }
        while (!mmx.empty() && mmx.front().first < arr[i]) {
            mmx.pop_back();
        }
        while (!mmn.empty() && mmn.front().first > arr[i]) {
            mmn.pop_back();
        }
        mmx.push_back({ arr[i],i });
        mmn.push_back({ arr[i],i });
        if (mmx.front().first - mmn.front().first <= c) {
            ans.push_back(i-m);
        }
    }
    for (auto& i : ans) {
        if (i >= 0) {
            cout << i+1 << '\n';
        }
    }
}