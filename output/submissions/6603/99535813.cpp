#include <bits/stdc++.h>

using namespace std;

int k = 0;

int arr[20];
int use[20];

void go(int i, int j){
    if(i == 6){
        for(int a=0;a<6;a++){
            cout << use[a] << ' ';
        }
        cout << '\n';
    }
    for(int a = 0;a<8&&j+a<k;a++){
    use[i] = arr[j+a];
    go(i+1,j+a+1);
    use[i] = 0;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    while(1){
        cin >> k;
        if(!k){ return 0; }
        for(int i=0;i<k;i++){
            cin >> arr[i];
        }
        go(0, 0);
        cout << '\n';
    }
}