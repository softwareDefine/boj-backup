#include <bits/stdc++.h>

using namespace std;

int n;
int arr[200][200];
map<pair<int,int>,pair<int,int>> mp;

int mmx;

int main(){
    cin >> n;
    while(n--){
        int x,y;
        cin >> x >> y;
        for(int i=x;i<x+11;i++){
            for(int j=y;j<y+11;j++){
                arr[i][j] = 1;
            }
        }
    }
    for(int i=1;i<=100;i++){
        int start=0,end=0,cnt=0;
        for(int j=1;j<=100;j++){
            if(arr[i][j]){
                if(!cnt){
                    start = j;
                }
                cnt++;
                continue;
            }
            if(cnt){
                end = j-1;
                if(mp[{start,end}] == i-1){

                }
                mp[{start,end}] = {i,1};
                cnt = 0;
            }
        }
        
    }
}