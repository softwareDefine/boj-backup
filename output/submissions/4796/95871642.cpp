#include <bits/stdc++.h>

using namespace std;

int i;

int main()
{
    while(1){
        int l,p,v;
        i++;
        cin >> l >> p >> v;
        if(l == 0){break;}
        cout << "Case " << i << ":" << (v/p)*l + min(v%p,l) << '\n';
    }
    return 0;
}