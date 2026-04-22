#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> ans(n, 0);
    int max1 = a[0], max2 = INT_MIN;

    for (int i = 1; i < n; ++i) {
        int curr = a[i];
        if (curr > max1) {
            max2 = max1;
            max1 = curr;
        } else if (curr > max2) {
            max2 = curr;
        }
        ans[i] = max2;
    }

    for (int i = 1; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
