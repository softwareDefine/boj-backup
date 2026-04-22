#include <iostream>
#include <string>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;
    if (K > N - 1) {
        cout << "No" << endl;
        return 0;
    }
    if (N % 2 == 0) {
        if (K % 2 == 0 && K != 0 && K != N - 1) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    string S(N, 'a');
    long long D = N - 1 - K;
    if (D == 0) {
        // Do nothing, S is already 'a's with f(S) = N - 1
    } else {
        if (N % 2 == 1) {
            // N is odd, decrease f(S) by changing one character per decrease
            long long cnt = 0;
            int left = N / 2;
            int right = N / 2;
            while (cnt < D && (left >= 0 || right < N)) {
                if (cnt < D) {
                    if (left >= 0) {
                        S[left] = 'b';
                        cnt++;
                        left--;
                    }
                }
                if (cnt < D) {
                    if (right < N && right != left) {
                        S[right] = 'b';
                        cnt++;
                        right++;
                    }
                }
            }
        } else {
            // N is even, decrease f(S) by 2 per pair of symmetric changes
            if (D % 2 == 1 && K != 0) {
                // Impossible
                // Should not reach here due to earlier checks
                cout << "No" << endl;
                return 0;
            }
            long long cnt = 0;
            int offset = 0;
            while (cnt < D && (N / 2 - offset - 1 >= 0)) {
                S[N / 2 - offset - 1] = 'b';
                S[N / 2 + offset] = 'b';
                cnt += 2;
                offset++;
            }
            if (cnt < D) {
                // Not enough positions to change
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << S << endl;
    return 0;
}
