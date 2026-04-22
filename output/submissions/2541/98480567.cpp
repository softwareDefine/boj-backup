#include <bits/stdc++.h>

using namespace std;

int a,b;

int chk[300000];
int flag;
int diff;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    fill(chk,chk+300000,99999999);
    cin >> a >> b;
    if(b < a){swap(a,b); flag =1;}
    diff = b-a;
    if(diff != 0){
        while(diff%2 == 0){
            diff /= 2;
        }
    }
    int t = 5;
    while(t--){
        int s,e;
        cin >> s >> e;
        if(flag){swap(s,e);}
        if(!diff){
            if(e -s >= 0){
            cout << 'Y' << '\n';
            }else{
                cout << 'N' << '\n';
            }
        }else{
            if(e-s >0 && ((e-s) % diff) == 0){
                cout << 'Y' << '\n';
            }else{
                cout << 'N' << '\n';
            }   
        }
    }
}