#include <bits/stdc++.h>

using namespace std;

int res[6][3];
int chk[6][3];
int flag;

void go(int i,int j){
    if(flag){
        return;
    }
    if(i <= j){
        if(i==j && i==5){
            for(int i=0;i<6;i++){
                for(int j=0;j<3;j++){
                    if(chk[i][j] != res[i][j]){
                        return;
                    }
                }
            }
            flag = 1;
            cout << 1 << ' ';
            return;
        }
        go(i+1,0);
        return;
    }
    for(int k=1;k<=3;k++){
        if(k == 1){
            chk[j][0]++;
            chk[i][2]++;
        }else if(k == 2){
            chk[i][0]++;
            chk[j][2]++;
        }else{
            chk[i][1]++;
            chk[j][1]++;
        }
        go(i,j+1);
        if(k == 1){
            chk[j][0]--;
            chk[i][2]--;
        }else if(k == 2){
            chk[i][0]--;
            chk[j][2]--;
        }else{
            chk[i][1]--;
            chk[j][1]--;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int t=0;t<4;t++){
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                cin >> res[i][j];
            }
        }
        flag = 0;
        go(1,0);
        if(!flag){
            cout << 0 << ' ';
        }
    }
}