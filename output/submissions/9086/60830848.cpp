#include <iostream>
#include <string>

using namespace std;
int n;
long long sum;
long long a,b,c,d;
long long arr[110];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a ;
    for (int i = 0; i < a; i++) {
        string str;
        cin >> str;
        cout << str[0] << str[str.length() - 1] << '\n';
    }
}