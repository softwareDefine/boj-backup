#include <iostream>
using namespace std;

int r, c, cnt;
char arr[110][110];

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char a;
            cin >> a;
            if (arr[i][j] == a) {
                cnt++;
            }
        }
    }
    cout << cnt;
}