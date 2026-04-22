#include <bits/stdc++.h>

using namespace std;

int n;
int dice[51000][6];
int sum[6];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            cin >> dice[i][j];
        }
    }
    for(int i=0;i<6;i++){
        int before = i;
        int next;
        for(int j=0;j<n;j++){
            if(before == 0){
                int mmx = 0;
                for(int k=0;k<6;k++){
                    if(k !=5 && k!= 0){
                        mmx = max(mmx,dice[j][k]);
                    }
                }
                sum[i] += mmx;
                int next = dice[j][5];
                if(j == n-1) {continue; }
                for(int k=0;k<6;k++){
                    if(dice[j+1][k] == next){
                        before = k;
                        break;
                    }
                }
            }else if(before == 1){
                int mmx = 0;
                for(int k=0;k<6;k++){
                    if(k !=1 && k!= 3){
                        mmx = max(mmx,dice[j][k]);
                    }
                }
                sum[i] += mmx;
                int next = dice[j][3];
                if(j == n-1) {continue; }
                for(int k=0;k<6;k++){
                    if(dice[j+1][k] == next){
                        before = k;
                        break;
                    }
                }
            }else if(before == 2){
                int mmx = 0;
                for(int k=0;k<6;k++){
                    if(k !=2 && k!= 4){
                        mmx = max(mmx,dice[j][k]);
                    }
                }
                sum[i] += mmx;
                int next = dice[j][4];
                if(j == n-1) {continue; }
                for(int k=0;k<6;k++){
                    if(dice[j+1][k] == next){
                        before = k;
                        break;
                    }
                }
            }else if(before == 3){
                int mmx = 0;
                for(int k=0;k<6;k++){
                    if(k !=1 && k!= 3){
                        mmx = max(mmx,dice[j][k]);
                    }
                }
                sum[i] += mmx;
                int next = dice[j][1];
                if(j == n-1) {continue; }
                for(int k=0;k<6;k++){
                    if(dice[j+1][k] == next){
                        before = k;
                        break;
                    }
                }
            }else if(before == 4){
                int mmx = 0;
                for(int k=0;k<6;k++){
                    if(k !=2 && k!= 4){
                        mmx = max(mmx,dice[j][k]);
                    }
                }
                sum[i] += mmx;
                int next = dice[j][2];
                if(j == n-1) {continue; }
                for(int k=0;k<6;k++){
                    if(dice[j+1][k] == next){
                        before = k;
                        break;
                    }
                }
            }else if(before == 5){
                int mmx = 0;
                for(int k=0;k<6;k++){
                    if(k !=0 && k!= 5){
                        mmx = max(mmx,dice[j][k]);
                    }
                }
                sum[i] += mmx;
                int next = dice[j][0];
                if(j == n-1) {continue; }
                for(int k=0;k<6;k++){
                    if(dice[j+1][k] == next){
                        before = k;
                        break;
                    }
                }
            }
        }
    }
    int mmx = 0;
    for(int i=0;i<6;i++){
        mmx = max(mmx,sum[i]);
    }
    cout << mmx;
}