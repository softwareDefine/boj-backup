#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> S; // The sequence of numbers
vector<int> P; // The possibilities

bool isPossible(int K) {
    vector<int> S_prime; // The sequence after deleting numbers with P[i] ≤ K
    for (int i = 0; i < N; ++i) {
        if (P[i] > K) {
            S_prime.push_back(S[i]);
        }
    }

    int len = S_prime.size();
    int i = 0;
    while (i < len) {
        int L = S_prime[i];
        if (L <= 0) {
            return false; // Invalid length
        }
        if (i + L > len) {
            return false; // Not enough numbers for the fragment
        }
        i += L; // Move to the next fragment
    }

    return i == len; // Successfully parsed the entire sequence
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    S.resize(N);
    P.resize(N);
    int max_P = 0;
    int min_P = 100001;

    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    vector<int> unique_P;
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        max_P = max(max_P, P[i]);
        min_P = min(min_P, P[i]);
        unique_P.push_back(P[i]);
    }

    // Remove duplicates and sort the possibilities
    sort(unique_P.begin(), unique_P.end());
    unique_P.erase(unique(unique_P.begin(), unique_P.end()), unique_P.end());

    int left = 0;
    int right = unique_P.size() - 1;
    int answer = max_P + 1; // Initialize with an impossible high value

    while (left <= right) {
        int mid = (left + right) / 2;
        int K = unique_P[mid];
        if (isPossible(K)) {
            answer = K;
            right = mid - 1; // Try to find a smaller K
        } else {
            left = mid + 1;
        }
    }

    if (answer > max_P) {
        cout << max_P << '\n'; // If no deletion is needed, output max_P
    } else {
        cout << answer << '\n';
    }

    return 0;
}
