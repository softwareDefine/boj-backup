#include <iostream>
#include <string>

using namespace std;
int a, b, c, d, e;
int arr[31];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 1; i <= 28; i++) {
        int a;
        cin >> a;
        arr[a]++;
    }
    for (int i = 1; i <= 30; i++) {
        if (!arr[i]) {
            cout << i << '\n';
        }
    }
}