#include <iostream>

using namespace std;

int a, b, c , now;
int cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c;
    if (c==0) {
        cout << 0;
    }
    else if (a > c) {
        cout << 1;
    }
    else{
        cout << (int)((c-b-1)/(a-b)+1);
    }
    
}
