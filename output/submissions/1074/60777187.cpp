#include <iostream>
#include <cmath>

using namespace std;

int N,r,c,ans;

int main() {
    cin >> N >> r >> c;

    int y = pow(2, N)/2;
    int x = y;
    

    while (N-- > 0) {
        int temp = pow(2, N)/2;
        int skip = pow(4, N);
 
        if (r < y && c < x) {
            x -= temp;
            y -= temp;
        } else if (r < y && x <= c) {
            x += temp;
            y -= temp;
            ans += skip;
        } else if (y <= r && c < x) {
            x -= temp;
            y += temp;
            ans += skip * 2;
        } else {
            x += temp;
            y += temp;
            ans += skip * 3;
        }
    }
    cout << ans;
}