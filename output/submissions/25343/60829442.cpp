#include <iostream>

using namespace std;

int num;

int lis[130][130];
int arr[130][130];
int mmx=1;

int main()
{
    cin >> num;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            lis[i][j] = 1;
            for (int k = 0; k <= i; k++) {
                for (int r = 0; r <= j; r++) {
                    if (arr[i][j] > arr[k][r]) {
                        lis[i][j] = max(lis[i][j], lis[k][r] + 1);
                        mmx = max(lis[i][j], mmx);
                    }
                }
            }
        }
    }
    cout << mmx;
}