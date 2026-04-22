#include <bits/stdc++.h>

using namespace std;

int n;

void go(int n,int from,int to,int via){
    if(n!=1){
    go(n-1,from,via,to);   
    }
    cout << from << ' ' << to << '\n';
    if(n!=1){
    go(n-1,via,to,from);
    }
}

int main(){
    cin >> n;
    cout << pow(2,n)-1 << '\n';
    go(n,1,3,2);
}