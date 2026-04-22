#include <bits/stdc++.h>

using namespace std;

int a,b;
int c;
int main(){
    cin >> a >> b;
    cin >> c;
    b+= c;
    a+= b/60;
    b %= 60;
    a%=24;
    cout << a << ' ' << b;
}