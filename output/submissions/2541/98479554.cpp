#include <bits/stdc++.h>

using namespace std;

int a,b;

int chk[200000];
int flag;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    fill(chk,chk+100000,99999999);
    cin >> a >> b;
    if(b < a){swap(a,b); flag =1;}
    int diff = b-a;
    if(diff != 0){
    while(diff%2 == 0){
        chk[diff] = a;
        if(a%2!=0){
            a++;
        }
        a/=2;
        diff/=2;
    }
    chk[diff] = a;
    for(int i=2;i*diff <= 100000;i++){
        chk[i*diff] = a;
    }
    }else{
        for(int i=0;i<= 100000;i++){
            chk[i] = 1;
        }
    }
    int t = 5;
    while(t--){
        int s,e;
        cin >> s >> e;
        if(flag){swap(s,e);}
        if(e-s >= 0&&chk[e-s] <= s){
            cout << 'Y' << '\n';
        }else{
            cout << 'N' << '\n';
        }
    }
}