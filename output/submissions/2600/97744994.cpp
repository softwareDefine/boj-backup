#include <bits/stdc++.h>

using namespace std;

int b1,b2,b3;
int starter[500][500][2];
int cnt =0;
bool go(int a,int b,int level){
    //cout << a << ' ' << b << '\n';
    int chk[6] = {-1,-1,-1,-1,-1,-1};
    if(a==0 && b==0){
        if(level % 2 == 0){
            return 1;
        }else{
            return 0;
        }
    }
    if(starter[a][b][level%2] != 3){
        return starter[a][b][level%2];
    }
    if(a-b1 >=0){
        chk[0]=go(a-b1,b,level+1);
        starter[a-b1][b][(level+1)%2] = chk[0];
    }
    if(a-b2 >=0){
        chk[1]=go(a-b2,b,level+1);
        starter[a-b2][b][(level+1)%2] = chk[1];
    }
    if(a-b3 >=0){
        chk[2]=go(a-b3,b,level+1);
        starter[a-b3][b][(level+1)%2] = chk[2];
    }
    if(b-b1 >=0){
       chk[3]=go(a,b-b1,level+1);
       starter[a][b-b1][(level+1)%2] = chk[3];
    }
    if(b-b2 >=0){
       chk[4]=go(a,b-b2,level+1);
       starter[a][b-b2][(level+1)%2] = chk[4];
    }
    if(b-b3 >=0){
        chk[5]=go(a,b-b3,level+1);
        starter[a][b-b3][(level+1)%2] = chk[5];
    }
    if(level%2==0){
        int myans=0;
        for(int i=0;i<6;i++){
            if(chk[i] == -1){
                continue;
            }
            if(chk[i] == 0){
                myans++;
            }
        }
        if(myans){
            starter[a][b][level%2] = 0;
            return 0;
        }else{
            starter[a][b][level%2] = 1;
            return 1;
        }
        return !myans;
    }
    if(level%2==1){
        int myans = 0;
        for(int i=0;i<6;i++){
            if(chk[i] == -1){
                continue;
            } 
            if(chk[i] == 1){
                myans++;
            }
        }
         if(myans){
            starter[a][b][level%2] = 1;
            return 1;
        }else{
            starter[a][b][level%2] =0;
            return 0;
        }
        return myans;
    }
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    cin >> b1 >> b2 >> b3;
    for(int i=0;i<5;i++){
        for(int a = 0;a<500;a++){
            for(int b=0;b<500;b++){
                starter[a][b][0] = 3;
                starter[a][b][1] = 3;
            }
        }
        int k1,k2;
        cin >> k1 >> k2;
        if(go(k1,k2,1)){
            cout << 'A' << '\n';
        }else{
            cout << 'B' << '\n';
        }
    }
}