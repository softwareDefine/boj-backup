#include <iostream>
#include <string>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;

    if (K < 0 || K >= N) {
        cout << "No" << endl;
        return 0;
    }

    if (N % 2 == 0 && K == N - 2) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    string S(N, 'a');

    if (K == N - 1) {
        // All prefixes and suffixes are palindromic.
        // No changes needed.
    }
    else if (K == 0) {
        // Need to make all prefixes or suffixes non-palindromic.
        // Alternate characters to break palindromicity.
        for (int i = 0; i < N; ++i) {
            S[i] = (i % 2 == 0) ? 'a' : 'b';
        }
    }
    else {
        // Decrease f(S) by N - 1 - K
        int D = N - 1 - K;
        int left = 0, right = N - 1;
        while (D > 0 && left < right) {
            // Break palindromicity by changing symmetric characters.
            S[left] = 'b';
            S[right] = 'c';
            D--;
            left++;
            right--;
        }
        if (D > 0) {
            // If N is odd, change the middle character if necessary.
            if (left == right) {
                S[left] = 'b';
                D--;
            }
        }
    }

    cout << S << endl;

    return 0;
}
