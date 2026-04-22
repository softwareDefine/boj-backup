#include <iostream>

using namespace std;

int n, q;
int save;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for (int s = 0; s < q; s++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            if (save == 0) {
                save = 1;
            }
            else if (save == 1) {
                save = 0;
            }
        }
        else {
            if (((c - b + 1)/2) % 2 == 0) {
            }
            else {
                if (save == 0) {
                    save = 1;
                }
                else if (save == 1) {
                    save = 0;
                }
            }
        }
        cout << save << '\n';
    }
}