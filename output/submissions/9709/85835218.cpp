#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T; // Number of test cases
    cin >> T;
    for (int case_num = 1; case_num <= T; ++case_num) {
        int R, C;
        cin >> R >> C;
        vector<string> bulbs(R);
        for (int i = 0; i < R; ++i) {
            cin >> bulbs[i];
        }

        // Create a flip matrix of size (R+1) x (C+1) initialized to 0
        vector<vector<int>> flip(R + 1, vector<int>(C + 1, 0));
        int ans = 0; // Minimum number of flips required

        // Process the grid from bottom-right to top-left
        for (int i = R - 1; i >= 0; --i) {
            for (int j = C - 1; j >= 0; --j) {
                // Calculate cumulative flips at position (i, j)
                int cumulative_flip = flip[i + 1][j] + flip[i][j + 1] - flip[i + 1][j + 1];
                int total_flip = cumulative_flip % 2;

                // Determine the bulb's state after flips
                char bulb_state = bulbs[i][j];
                if (total_flip % 2 == 1) {
                    // If total flips is odd, bulb state is toggled
                    bulb_state = (bulb_state == '1') ? '0' : '1';
                }

                if (bulb_state == '1') {
                    // Bulb is on, no need to flip
                    flip[i][j] = 0;
                } else {
                    // Bulb is off, need to flip at (i, j)
                    flip[i][j] = 1;
                    ans++;
                }
            }
        }

        cout << "Case #" << case_num << ": " << ans << endl;
    }
    return 0;
}
