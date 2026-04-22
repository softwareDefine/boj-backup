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
    do
    {
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }
        cout << a + b << '\n';
    } while (1);
}