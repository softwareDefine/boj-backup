#include <bits/stdc++.h>

using namespace std;

int n;
int mp[20][20];
int cnt;

void go(int now){
    //cout << now << '\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int chk = 0;
            if(!mp[i][j]){
                mp[i][j] = 2;
                for(int a=1;a<=n;a++){
                    for(int b=1;b<=n;b++){
                        if(a == i && b == j){ continue; }
                        if((abs(i-a) == abs(j-b) || a == i || b == j)){
                            if(mp[a][b] == 2){
                                chk =1;
                                break;
                            }
                        }
                    }
                    if(chk) {
                        break;
                    }
                }
                if(!chk){
                    if(now == n){
                        cnt++;
                        mp[i][j] = 0;
                        return;
                    }
                    go(now+1);
                }
                mp[i][j] = 0;
            }
        }
        
    }
}

int main(){
    cin >> n;
    go(1);
    cout << cnt;
}