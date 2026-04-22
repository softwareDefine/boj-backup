#include <bits/stdc++.h>

using namespace std;

int a,b;

int chk[300000];
int flag;
int befdiff;
int diff;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    fill(chk,chk+300000,99999999);
    cin >> a >> b;
    if(b < a){swap(a,b); flag =1;}
    diff = b-a;
    befdiff = b-a;
    if(diff != 0){
            while(befdiff%2 == 0){
                chk[befdiff] = a;
                if(a%2!=0){
                    a++;
                }
                a/=2;
                befdiff/=2;
            }
            chk[befdiff] = a;
            for(int i=2;i*diff <= 100000;i++){
                chk[i*befdiff] = a;
            }
            while(diff%2 == 0){
                diff /= 2;
            }
            for(int i=1;i*diff<=100000;i++){
                chk[i*diff] = min(chk[i*diff],diff); 
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
            if(e-s >= 0&&chk[e-s] <= s){
                cout << 'Y' << '\n';
            }else{
                cout << 'N' << '\n';
            }   
        }
    }
}