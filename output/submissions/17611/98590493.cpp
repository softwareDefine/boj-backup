#include <bits/stdc++.h>

using namespace std;

int n;

pair<int,int> coor[300000];
int xline[2000000];
int yline[2000000];
int mmx;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        coor[i] = coor[n+i] = {x,y};
    }
    for(int i=0;i<n;i++){
        if(coor[i+1].first == coor[i].first){
            if(coor[i].second > coor[i+1].second){
                yline[coor[i+1].second+ 500000] += 1;
                yline[coor[i].second+1+ 500000] -= 1;
            }else{
                yline[coor[i].second+ 500000] += 1;
                yline[coor[i+1].second+1+ 500000] -= 1;
            }
        }else{
            if(coor[i].first > coor[i+1].first){
                xline[coor[i+1].first+ 500000] += 1;
                xline[coor[i].first+1+ 500000] -= 1;
            }else{
                xline[coor[i].first + 500000] += 1;
                xline[coor[i+1].first+1+ 500000] -= 1;
            }
        }
    }
    mmx = max(mmx,xline[0]);
    mmx = max(mmx,yline[0]);
    for(int i=1;i<=2000000;i++){
        xline[i] += xline[i-1];
        yline[i] += yline[i-1];
        mmx = max(mmx,max(xline[i],yline[i]));
    }
    cout << mmx;
}