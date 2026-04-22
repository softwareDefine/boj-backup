#include <bits/stdc++.h>

using namespace std;

int chk[100000];
int a,b,c,d;
int mmn = 99999;
int cnt;
int my;

int main(){
    cin >> a >> b >> c >> d;
    my = a*1000 + b*100 + c*10 + d;
    for(int i=0;i<4;i++){
        chk[my] = 1;
        mmn = min(mmn,my);
        my = my/10 + (my%10)*1000;
    }
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            for(int k=1;k<=9;k++){
                for(int l=1;l<=9;l++){
                    int tmp = i*1000 + j*100 + k*10 + l;
                    if(tmp == mmn){
                        l = 10;
                        k = 10;
                        j = 10;
                        i = 10;
                    }
                    if(!chk[tmp]){
                        cnt++;
                        for(int m=0;m<4;m++){
                            chk[tmp] = 1;
                            tmp = tmp/10 + (tmp%10)*1000;
                        }
                    }
                }
            }
        }
    }
    cout << cnt+1;
}