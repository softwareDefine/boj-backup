#include <iostream>
#include <string>

using namespace std;
int n;
int a,b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (cin >> a >> b) {
        cout << a + b << '\n';
    }
}