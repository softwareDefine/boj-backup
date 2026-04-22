#include<bits/stdc++.h>

using namespace std;

int n,x;
int mmx = -99999999;


int main(){
    cin >> n  >> x;
    for(int i=0;i<n;i++){
        int y,z;
        cin >> y >> z;
        if(y+z <= x){
            mmx = max(mmx,y);
        }
    }
    if(mmx == -99999999){
        cout << -1;
    }else{
        cout << mmx;
    }
}