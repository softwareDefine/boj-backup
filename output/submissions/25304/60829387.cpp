#include <iostream>
#include <string>

using namespace std;
int n;
long long sum;
long long a,b,c,d;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a ;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b >> c;
        sum += b * c;
    }
    if (sum == a) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}