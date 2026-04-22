#include <iostream>
#include <string>

using namespace std;

string n;
int visitied[10010];
int visitied2[10010];
int cnt = 0;
int cnt2 = 0;
int main()
{
    cin >> n;
    for (int i = 0; i < n.length(); i++) {
        if (n[i] == 'C' && visitied[i] == 0) {
            int j = i - 1;
            while (j >= 0) {
                if (n[j] == 'B' && visitied[j] == 0) {
                    visitied[j] = 1;
                    visitied[i] = 1;
                    cnt++;
                    break;
                }
                j--;
            }

        }
        else
            if (n[i] == 'B' && visitied[i] == 0) {
                int j = i - 1;
                while (j >= 0) {
                    if (n[j] == 'A' && visitied[j] == 0) {
                        visitied[j] = 1;
                        visitied[i] = 1;
                        cnt++;
                        break;
                    }
                    j--;
                }

            }
    }
    for (int i = 0; i < n.length(); i++) {
        if (n[i] == 'C' && visitied2[i] == 0) {

            int j = i - 1;
            while (j >= 0) {
                if (n[j] == 'B' && visitied2[j] == 0) {
                    visitied2[j] = 1;
                    visitied2[i] = 1;
                    cnt2++;
                    break;
                }
                j--;
            }
        }
    }
    for (int i = 0; i < n.length(); i++) {
        if (n[i] == 'B' && visitied2[i] == 0) {

            int j = i - 1;
            while (j >= 0) {
                if (n[j] == 'A' && visitied2[j] == 0) {
                    visitied2[j] = 1;
                    visitied2[i] = 1;
                    cnt2++;
                    break;
                }
                j--;
            }
        }
    }
    cout << max(cnt,cnt2);
}