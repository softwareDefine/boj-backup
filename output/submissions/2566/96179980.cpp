#include <bits/stdc++.h>

using namespace std;
pair<int,int> mmxidx;
int ch;
int mmx = -1;

int main(){
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cin >> ch;
            if(mmx < ch){
                mmx = ch;
                mmxidx = {i,j};
            }
        }
    }
    cout << mmx << '\n';
    cout << mmxidx.first << ' ' << mmxidx.second;
}