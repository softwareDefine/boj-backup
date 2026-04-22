#include <iostream>

using namespace std;

int N;

int house[17][17];

long long dp[17][17][3]; 

// dp[r][c][d]: (r,c)에 파이프 끝부분이 있고, 방향이 d(0:가로, 1:세로, 2:대각선)일 때 경우의 수

int main() {

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {

        for (int j = 1; j <= N; j++) {

            cin >> house[i][j];

        }

    }

    

    // 초기 상태: (1,1), (1,2)에 파이프, 가로 방향

    dp[1][2][0] = 1;

    for (int r = 1; r <= N; r++) {

        for (int c = 1; c <= N; c++) {

            if (house[r][c] == 1) continue; // 벽이면 진행 불가

            // 가로 상태에서의 이동

            if (dp[r][c][0] > 0) {

                // 가로 이동 (→)

                if (c+1 <= N && house[r][c+1] == 0) {

                    dp[r][c+1][0] += dp[r][c][0];

                }

                // 대각선 이동 (↘)

                if (r+1 <= N && c+1 <= N && house[r][c+1] == 0 && house[r+1][c] == 0 && house[r+1][c+1] == 0) {

                    dp[r+1][c+1][2] += dp[r][c][0];

                }

            }

            // 세로 상태에서의 이동

            if (dp[r][c][1] > 0) {

                // 세로 이동 (↓)

                if (r+1 <= N && house[r+1][c] == 0) {

                    dp[r+1][c][1] += dp[r][c][1];

                }

                // 대각선 이동 (↘)

                if (r+1 <= N && c+1 <= N && house[r][c+1] == 0 && house[r+1][c] == 0 && house[r+1][c+1] == 0) {

                    dp[r+1][c+1][2] += dp[r][c][1];

                }

            }

            // 대각선 상태에서의 이동

            if (dp[r][c][2] > 0) {

                // 가로 이동 (→)

                if (c+1 <= N && house[r][c+1] == 0) {

                    dp[r][c+1][0] += dp[r][c][2];

                }

                // 세로 이동 (↓)

                if (r+1 <= N && house[r+1][c] == 0) {

                    dp[r+1][c][1] += dp[r][c][2];

                }

                // 대각선 이동 (↘)

                if (r+1 <= N && c+1 <= N && house[r][c+1] == 0 && house[r+1][c] == 0 && house[r+1][c+1] == 0) {

                    dp[r+1][c+1][2] += dp[r][c][2];

                }

            }

        }

    }

    long long ans = dp[N][N][0] + dp[N][N][1] + dp[N][N][2];

    cout << ans << "\n";

    return 0;

}