#include <bits/stdc++.h>

using namespace std;

int k,c;
int visited[2000][2000];
bool chk[2000][2000][2000][2];
void dfs(int now,int i,int j,int turn){
    if(chk[now][i][j][turn]){return;}
    chk[now][i][j][turn] = 1;
    if(turn == 0){
        visited[i+1][j] =1;
        visited[i][j] =1;
        if(k-now + i+1 >= j && i+1 <= j + k-now){
            dfs(now,i+1,j,1);
        }
        if(k-now + i >= j && i <= j + k-now){
            dfs(now,i,j,1);
        }
    }else{
            visited[i][j] =1;
            visited[i][j+1] =1;
        if(k-now+1 + i >= j && i <= j + k-now+1){
            dfs(now+1,i,j,0);
        }
        if(k-now+1 + i >= j+1 && i <= j+1 + k-now+1){
            dfs(now+1,i,j+1,0);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> k;
    dfs(1,0,0,0);
    cin >> c;
    while(c--){
        int i,j;
        cin >> i >> j;
        cout  << visited[i][j] << '\n';
    }
}