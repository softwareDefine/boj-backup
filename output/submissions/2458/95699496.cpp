#include <bits/stdc++.h>

using namespace std;

int dist[600][600];
int cnt;

int main(){
    for(int i=0;i<600;i++){
        for(int j=0;j<600;j++){
            if(i==j){
                dist[i][j] = 0;
                continue;
            }
            dist[i][j] = 9999;
        }
    }
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        dist[a][b] = 1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        int flag = 0;
        for(int j=1;j<=n;j++){
            if(dist[i][j] == 9999 && dist[j][i] == 9999){
                flag =1;
                break;
            }
        }
        if(!flag){
            cnt++;
        }
    }
    cout << cnt;
}