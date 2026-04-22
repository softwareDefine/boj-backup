#include <iostream>
#include <vector>

using namespace std;

long long n;
long long arr[10010];
long long dp[100010];
long long mmx;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        dp[i] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[j] + arr[i], dp[i]);
            }
        } 
    }
    mmx = -999999999;
    for (int i = 0; i < n; i++) {
        mmx = max(dp[i], mmx);
    }
    cout << mmx;
}