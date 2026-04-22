#include <bits/stdc++.h>

using namespace std;

int t;

int main(){
    cin >> t;
    while(t--){
        int l, n; 
        int mmx = 0, mmn = 0;
        cin >> l >> n;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            mmx = max(mmx,max(l-a,a));
            mmn = max(mmn,min(l-a,a));
        }
        cout << mmn << ' ' << mmx << '\n';
    }
}