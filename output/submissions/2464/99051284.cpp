#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n;
bitset<100> bl, bh;
int possible = -1;
int ls = 0, lh = 0;
int cnt = 0;

int main(){
    cin >> n;
    bl = bitset<100>(n);
    bh = bitset<100>(n);
    for(int i=0;i<100;i++){
        if(possible != -1 && bl[i]){
            bl.set(possible,1);
            bl.set(i,0);
            ls = 1;
            break;
        }
        if(!bl[i]){
            possible = i;
        }else{
            cnt++;
        }
    }
    for(int i=possible-1; i>=0;i--){
        if(cnt){
            cnt--;
            bl.set(i,1);
        }else{
            bl.set(i,0);
        }
    }
    if(ls){
        cout << bl.to_ullong() << ' ';
    }else{
        cout << 0 << ' ';
    }
    possible = -1;
    cnt = 0;
    for(int i=0;i<100;i++){
        if(possible != -1 && !bh[i]){
            bh.set(possible,0);
            bh.set(i,1);
            lh = 1;
            break;
        }
        if(bh[i]){
            possible = i;
        }else{
            cnt++;
        }
    }
    for(int i=possible-1; i>=0;i--){
        if(cnt){
            cnt--;
            bh.set(i,0);
        }else{
            bh.set(i,1);
        }
    }
    if(lh){
        cout << bh.to_ullong();
    }else{
        cout << 0;
    }
}