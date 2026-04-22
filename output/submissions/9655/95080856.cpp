#include <bits/stdc++.h>

using namespace std;

int n;
int winner[2000];

int main(){
    winner[0] = 1;
    for(int i=0;i<1000;i++){
        winner[i+1] |= winner[i];
        winner[i+3] |= winner[i];
    }
    cin >> n;
    if(winner[n]){
        cout << "SK";
    }else{
        cout << "CY";
    }
}