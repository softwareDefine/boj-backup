#include <bits/stdc++.h>

using namespace std;

int t;
pair<int,int> pos[500];
int dist[500][500];
inline int cal(pair<int,int> a,pair<int,int> b){
    return abs(a.first-b.first) + abs(a.second-b.second);
}

int main(){
    cin >> t;
    while(t--){
        for(int i=0;i<500;i++){
            for(int j=0;j<500;j++){
                if(i == j){
                    dist[i][j] = 0;
                    continue;
                }
                dist[i][j] = 9999999;
            }
        }
        int n;
        cin >> n;
        n += 2;
        for(int i=0;i<n;i++){
            int x,y;
            cin >> x >> y;
            pos[i] = {x,y};
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((cal(pos[i],pos[j])+49)/50 <= 20){
                    dist[i][j]=1;
                }
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j] = min(dist[i][j],dist[i][k]+ dist[k][j]);
                }
            }
        }
        if(dist[0][n-1] != 9999999){
            cout << "happy" << '\n';
        }else{
            cout << "sad" << '\n';
        }
    }
}