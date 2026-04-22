#include <bits/stdc++.h>

using namespace std;

int arr[6][6];
int res[6][3];
int chk[6][3];
int flag;

void go(int i,int j){
    if(i <= j){
        if(i==j && i==5){
            int chk[6][3] = {0, };
            for(int i=0;i<6;i++){
                for(int j=0;j<6;j++){
                    if(i <= j){
                        continue;
                    }
                    if(arr[i][j] == -1){
                        chk[j][0]++;
                        chk[i][2]++;
                    }else if(arr[i][j] == 1){
                        chk[i][0]++;
                        chk[j][2]++;
                    }else{
                        chk[i][1]++;
                        chk[j][1]++;
                    }
                }
            }
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
        arr[i][j] = k-2;
        go(i,j+1);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int t=0;t<4;t++){
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
                arr[i][j] = 0;
            }
        }
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