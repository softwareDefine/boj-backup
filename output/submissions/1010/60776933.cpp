#include <iostream>

using namespace std;

long long dp[50][50];
long long combination(int n, int m) {
    if (n == m) {
        return 1;
    }
    if (m == 1) {
        return 1;
    }
    return  combination(n - 1, m - 1) + combination(n - 1, m);
}

int main()
{
    int T, N, M;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 1; i <= 30; i++) {
        dp[i][0] = dp[i][i] = 1;
        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        cout << dp[N > M ? N : M][N < M ? N : M] << '\n';
    }

    return 0;
}