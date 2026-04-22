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
    if (N % 2 == 0 && K % 2 == 0 && K != 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    string S(N, 'a');
    long long cnt = N - 1;
    long long i = 1;
    while (cnt > K && i < N) {
        if (i <= N / 2) {
            if (S[N - i] == 'a') {
                S[N - i] = 'b';
                cnt--;
            }
        } else {
            if (S[i - 1] == 'a') {
                S[i - 1] = 'b';
                cnt--;
            }
        }
        i++;
    }
    cout << S << endl;
    return 0;
}
