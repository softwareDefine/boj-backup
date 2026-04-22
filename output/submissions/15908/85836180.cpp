#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100005;

int N;
vector<int> S;
vector<int> P;

bool isPossible(int K) {
    vector<bool> removed(N + 1, false);
    vector<int> sum_removed(N + 2, 0);
    vector<bool> dp(N + 2, false);

    // Build the removed array and sum_removed prefix sum
    for (int i = 1; i <= N; ++i) {
        if (P[i] <= K) {
            removed[i] = true;
        }
        sum_removed[i] = sum_removed[i - 1] + (removed[i] ? 1 : 0);
    }
    dp[N + 1] = true; // Base case

    // DP from N downto 1
    for (int i = N; i >= 1; --i) {
        if (removed[i]) {
            dp[i] = false;
            continue;
        }
        int L = S[i];
        int end_pos = i + L;

        if (end_pos > N) {
            dp[i] = false;
            continue;
        }

        int removed_in_range = sum_removed[end_pos] - sum_removed[i];

        if (removed_in_range == 0 && dp[end_pos + 1]) {
            dp[i] = true;
        } else {
            dp[i] = false;
        }
    }

    return dp[1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    S.resize(N + 1);
    P.resize(N + 1);
    int min_P = 100001;
    int max_P = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> S[i];
    }
    for (int i = 1; i <= N; ++i) {
        cin >> P[i];
        min_P = min(min_P, P[i]);
        max_P = max(max_P, P[i]);
    }

    int left = 0;
    int right = max_P;
    int answer = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (isPossible(mid)) {
            answer = mid;
            right = mid - 1; // Try to find a smaller K
        } else {
            left = mid + 1;
        }
    }

    if (answer == -1) {
        // Cannot parse the sequence even after removing all numbers
        cout << max_P << '\n';
    } else {
        cout << answer << '\n';
    }

    return 0;
}
