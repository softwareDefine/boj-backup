#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int ans;
int counter[100];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        counter[n]++;
    }
    for(int i=1;i<=50;i++){
        if(counter[i] == i){
            ans = i;
        }
    }
    if(counter[0] && !ans){cout << -1;}else if(!ans){
        cout << 0;
    }else{
        cout << ans;
    }
}