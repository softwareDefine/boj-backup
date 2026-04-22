#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int visited[10010];
int mmxd;
vector<pair<int, int>> vc;
int dp[10010];
int cmp(pair<int, int> a, pair<int, int> b) {
    if (b.second == a.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int day,score;
        cin >> day >> score;
        mmxd = max(day, mmxd);
        vc.push_back({ day,score });
    }
    stable_sort(vc.begin(), vc.end(), cmp);
    for (int i = 0; i < vc.size(); i++) {
        for (int j = vc[i].first; j > 0; j--) {
            if (dp[j] == 0) {
                dp[j] = vc[i].second;
                break;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= mmxd; i++) {
        sum += dp[i];
    }
    cout << sum;
}