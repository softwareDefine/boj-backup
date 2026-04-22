#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint total;
lint excep;

int main()
{
    cin >> total;
    for(int i=0;i<9;i++){
        lint tmp = 0;
        cin >> tmp;
        excep += tmp;
    }
    cout << total - excep;
    return 0;
}