#define fastio cin.tie(0)->sync_with_stdio(0)
#include <bits/stdc++.h>

using namespace std;

int a,b;
int cnt = 0;

int main(){
    fastio;
    cin >> a >> b;
    while(1){
        if(b < a){
            cout << "-1";
            return 0;
        }
        if(b == a){
            break;
        }
        if(b%2 == 0){
            b/=2;
        }else{
            if(b%10==1){
                b/=10;
            }else{
                cout << "-1";
                return 0;
            }
        }
        cnt++;
    }
    cout << cnt+1;
}