#include <iostream>
#include <string>

using namespace std;

int n, m;
string str[400];
int arr[400][400];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
            cin >> str[i];
            for (int j = 0; j < m; j++) {
                arr[i][j] = str[i][j] - '0';
            }
    }
    int all = 0;
    for (int i = 0; i < (1 << (n * m)); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            int smallsum = 0;
            for (int k = 0; k < m; k++) {
                int a = j * m + k;
                if ((i & (1 << a)) == 0) {
                    smallsum = smallsum * 10 + arr[j][k];
                }
                else {
                    sum += smallsum;
                    smallsum = 0;
                }
            }
            sum += smallsum;
        }
        for (int j = 0; j < m; j++) {
            int smallsum = 0;
            for (int k = 0; k < n; k++) {
                int a = k * m + j;
                if ((i & (1 << a)) != 0) {
                    smallsum = smallsum * 10 + arr[k][j];
                }
                else {
                    sum += smallsum;
                    smallsum = 0;
                }
            }
            sum += smallsum;
        }
        all = max(all, sum);
    }
    cout << all;
}