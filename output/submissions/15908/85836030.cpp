#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int N;
vector<int> sequence;
vector<int> possibility;

bool canParse(const vector<int>& hard_numbers) {
    int i = 0;
    int size = hard_numbers.size();
    while (i < size) {
        int L = hard_numbers[i];
        if (L < 1) {
            return false; // Length must be at least 1
        }
        i++;
        if (i + L - 1 >= size) {
            return false; // Not enough data numbers
        }
        i += L; // Move to the next length
    }
    return i == size;
}

bool isPossible(int K) {
    vector<int> hard_numbers;
    for (int i = 0; i < N; ++i) {
        if (possibility[i] > K) {
            hard_numbers.push_back(sequence[i]);
        }
    }
    return canParse(hard_numbers);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    sequence.resize(N);
    possibility.resize(N);
    set<int> unique_possibilities;

    int max_possibility = 0;
    for (int i = 0; i < N; ++i) {
        cin >> sequence[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> possibility[i];
        unique_possibilities.insert(possibility[i]);
        max_possibility = max(max_possibility, possibility[i]);
    }

    vector<int> possibilities_list(unique_possibilities.begin(), unique_possibilities.end());
    sort(possibilities_list.begin(), possibilities_list.end());

    int left = 0;
    int right = max_possibility;
    int answer = max_possibility;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (isPossible(mid)) {
            answer = mid;
            right = mid - 1; // Try to find a smaller K
        } else {
            left = mid + 1;
        }
    }

    cout << answer << '\n';

    return 0;
}
