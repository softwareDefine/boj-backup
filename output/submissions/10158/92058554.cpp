#include <bits/stdc++.h>

using namespace  std;

int w,h;
int p,q;
int t;

int main(){
    cin >> w >> h;
    cin >> p >> q;
    cin >> t;
    p += t,q += t;
    if((p/w)%2 != 0){
        cout << w-p%w;
    }else{
        cout << p%w;
    }
    cout << ' ';
    if((q/h)%2 != 0){
        cout << h-q%h;
    }else{
        cout << q%h;
    }
}
