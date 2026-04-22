#include <bits/stdc++.h>

using namespace std;

int v,e;
int mmn = 99999999;
int dist[500][500];

int main(){
    for(int i=0;i<500;i++){
        for(int j=0;j<500;j++){
            dist[i][j] = 99999999;
        }
    }
    cin >> v >> e;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }
    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for(int i=1;i<=v;i++){
        mmn = min(mmn,dist[i][i]);
    }
    if(mmn==99999999){
        cout << -1;
    }else{
        cout << mmn;
    }
}