#include <bits/stdc++.h>

using namespace std;

int cnt;
int arr[20];


int main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=1;i<=6;i++){
        cin >> arr[i];
    }
    cnt += arr[6];
    cnt += arr[5];
    arr[1] -= arr[5]*11;
    cnt += arr[4];
    arr[2] -= arr[4]*5;
    if(arr[2] < 0){arr[1] -= abs(arr[2])*4; }
    cnt += (arr[3]+3)/4;
    if(arr[3]%4 == 1){
        arr[2] -= 5;
        arr[1] -= 7;
    }else if(arr[3]%4 == 2){
        arr[2] -= 3;
        arr[1] -= 6;
    }else if(arr[3]%4 == 3){
        arr[2] -= 1;
        arr[1] -= 5;
    }
    if(arr[2] > 0){
        cnt += (arr[2]+8)/9;
        if(arr[2]%9){
            arr[1] -= (9-arr[2]%9)*4;
        }
    }
    if(arr[1] > 0){
        cnt += (arr[2]+35)/36;
    }
    cout << cnt;
}