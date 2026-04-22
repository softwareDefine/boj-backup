#include <iostream>

using namespace std;

int n;
int cnt;
int main()
{
    cin >> n;
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        if (a == n) {
            cnt++;
        }
    }
    cout << cnt;
}
