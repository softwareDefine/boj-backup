#include <bits/stdc++.h>

using namespace std;

int k,c;
int visited[2000][2000];
int allowed[2000][2000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> k;
    for(int now =1;now<=k;now++){
        for(int turn =0;turn<=1;turn++){
            
        for(int i=0;i<=k;i++){
            for(int j=0;j<=k;j++){
                allowed[i][j] = 0;
            }
        }
            for(int i=0;i<=k;i++){
            for(int j=0;j<=k;j++){
                if(!allowed[i][j]){continue;}
                if(turn == 0){
                    visited[i+1][j] =1;
                    visited[i][j] =1;
                    if(k-now + i+1 >= j && i+1 <= j + k-now){
                        allowed[i+1][j] =1;
                    }
                    if(k-now + i >= j && i <= j + k-now){
                        allowed[i][j]=1;
                    }
                }else{
                    visited[i][j] =1;
                    visited[i][j+1] =1;
                    if(k-now+1 + i >= j && i <= j + k-now+1){
                        allowed[i][j] = 1;
                    }
                    if(k-now+1 + i >= j+1 && i <= j+1 + k-now+1){
                        allowed[i][j+1] =1;
                    }
                }
            }
        }
        }
        
    }
    cin >> c;
    while(c--){
        int i,j;
        cin >> i >> j;
        cout  << visited[i][j] << '\n';
    }
}