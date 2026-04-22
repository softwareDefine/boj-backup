#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint ans;
lint k;

void factoring(){
    for(lint i=2;i*i <= 4*k*k;i++){
        if(4*k*k % i == 0){
            if((4*k*k/i) % 2 ==0 && i % 2 == 0 ){
                ans++;
            }
        }
    }
}

int main()
{
    cin >> k;
    factoring();
    cout << ans*2 << ' ' << ans*4*k;
    return 0;
}