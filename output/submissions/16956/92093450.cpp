#include<bits/stdc++.h>

using namespace std;

int r,c;
string mp[1000];
int chk = 1;

int main(){
    cin >> r >> c;
    for(int i=0;i<r;i++){
            cin >> mp[i];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mp[i][j] == 'W'){
                if(i-1 >= 0 && mp[i-1][j] == 'S'){
                    chk = 0;
                }
                if(i+1 < r && mp[i+1][j] == 'S'){
                    chk = 0;
                }
                if(j-1 >= 0 && mp[i][j-1] == 'S'){
                    chk = 0;
                }
                if(j+1 < c && mp[i][j+1] == 'S'){
                    chk = 0;
                }
            }
            if(!chk){break;}
        }
        if(!chk){ break; cout << 0; }
    }
    if(chk){
        cout << 1 << '\n';
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mp[i][j]=='.'){
                    cout << 'D';
                }else{
                    cout << mp[i][j];
                }
            }
            cout << '\n';
        }
    }
}