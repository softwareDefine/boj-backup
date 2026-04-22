#include <bits/stdc++.h>

using namespace std;

int n;
int winner[2000];

int main(){
    winner[0] = 1;
    for(int i=0;i<1000;i++){
        if(!winner[i+1]){
        winner[i+1] = winner[i]+1;
        }
        if(!winner[i+3]){
        winner[i+3] = winner[i]+1;
        }
        winner[i+4] = winner[i]+1;
    }
    cin >> n;
    if(winner[n] % 2 == 0){
        cout << "SK";
    }else{
        cout << "CY";
    }
}