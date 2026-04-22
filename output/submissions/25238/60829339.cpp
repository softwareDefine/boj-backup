#include <iostream>
#include <string>

using namespace std;
int n;
long long sum;
long long a,b,c,d;
int arr[30010];
int arr2[30010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    if (a - a * (b / 100.0) >= 100) {
        cout << '0';
    }
    else {
        cout << '1';
    }
}