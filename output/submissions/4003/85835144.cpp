#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int N, K, M;
vector<int> allowed;
vector<ll> sum_allowed;
vector<int> must_have_ninja;

int findBush(int Ai, int Bi) {
    int low = Ai, high = Bi;
    while (low < high) {
        int mid = (low + high) / 2;
        ll sum = sum_allowed[mid] - (Ai > 1 ? sum_allowed[Ai - 1] : 0);
        if (sum >= 1)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K >> M;
    allowed.assign(N + 2, 1); // 1-indexed
    vector<pair<int, int>> reports_C1;
    for (int i = 0; i < M; ++i) {
        int Ai, Bi, Ci;
        cin >> Ai >> Bi >> Ci;
        if (Ci == 0) {
            allowed[Ai] -= 1;
            allowed[Bi + 1] += 1;
        } else {
            reports_C1.emplace_back(Ai, Bi);
        }
    }
    // Build allowed[]
    for (int i = 1; i <= N; ++i) {
        allowed[i] += allowed[i - 1];
        allowed[i] = allowed[i] > 0 ? 1 : 0;
    }

    // Build sum_allowed[]
    sum_allowed.assign(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        sum_allowed[i] = sum_allowed[i - 1] + allowed[i];
    }

    // Process Ci=1 reports
    must_have_ninja.clear();
    for (auto& report : reports_C1) {
        int Ai = report.first;
        int Bi = report.second;
        ll count_i = sum_allowed[Bi] - sum_allowed[Ai - 1];
        if (count_i == 0) {
            cout << -1 << '\n';
            return 0;
        } else if (count_i == 1) {
            // Find the bush
            int bush = findBush(Ai, Bi);
            must_have_ninja.push_back(bush);
        }
    }

    // Remove duplicates and sort
    sort(must_have_ninja.begin(), must_have_ninja.end());
    must_have_ninja.erase(unique(must_have_ninja.begin(), must_have_ninja.end()), must_have_ninja.end());

    if (must_have_ninja.empty()) {
        cout << -1 << '\n';
    } else {
        for (int bush : must_have_ninja) {
            cout << bush << '\n';
        }
    }

    return 0;
}
