#include <bits/stdc++.h>

using namespace std;

int n;
int dist[100][100];
int ac;

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           cin >> dist[i][j];
        }
    }
    int i;
    for(i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                continue;
            }
            int flag =0;
            for(int k=1;k<=n;k++){
                if(dist[i][j] == dist[i][k]+dist[k][j] && k!=i && k!=j){
                    flag =1;
                }else if(dist[i][j] > dist[i][k] + dist[k][j]){
                    cout << -1;
                    return 0;
                }   
            }
            if(!flag && i <=n){
                //cout << i << ' ' << j << '\n';
                ac += dist[i][j];
            }
        }
    }
    cout << ac/2;
}