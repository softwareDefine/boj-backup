#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n;
lint now;

int main(){
    cin >> n;
    now = n;
    for(lint i=2;i*i<=n;i++){
        if(now % i == 0){
            n /= i;
            n *= (i-1);
        }
       while(now%i == 0){
            now /= i;
       }
    }
    if(now != 1){
        n /= now;
        n *= (now-1);
    }
    cout << n;
}