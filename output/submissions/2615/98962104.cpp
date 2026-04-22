#include <bits/stdc++.h>

using namespace std;

int arr[40][40];

int main(){
    for(int i=1;i<=19;i++){
        for(int j=1;j<=19;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1;i<=19;i++){
        for(int j=1;j<=19;j++){
            int last = -1;
            for(int k=0;k<6;k++){
                if(arr[i][j] && arr[i][j] == arr[i+k][j+k]){
                    last = k;
                }else{
                    break;
                }
            }
            if(last == 4&& arr[i-1][j-1] != arr[i][j]){
                cout << arr[i][j] << '\n';
                cout << i << ' ' << j;
                return 0;
            }
            last = -1;
            for(int k=0;k<6;k++){
                if(arr[i][j] && arr[i][j] == arr[i][j+k]){
                    last = k;
                }else{
                    break;
                }
            }
            if(last == 4 && arr[i][j-1] != arr[i][j]){
                cout << arr[i][j] << '\n';
                cout << i << ' ' << j;
                return 0;
            }
            last = -1;
            for(int k=0;k<6;k++){
                if(arr[i][j] && arr[i][j] == arr[i+k][j]){
                    last = k;
                }else{
                    break;
                }
            }
            if(last == 4 && arr[i-1][j] != arr[i][j]){
                cout << arr[i][j] << '\n';
                cout << i << ' ' << j;
                return 0;
            }
            for(int k=0;k<6;k++){
                if(arr[i][j] && j-k >=1&& arr[i][j] == arr[i+k][j-k]){
                    last = k;
                }else{
                    break;
                }
            }
            if(last == 4 && arr[i-1][j+1] != arr[i][j]){
                cout << arr[i][j] << '\n';
                cout << i+4 << ' ' << j-4;
                return 0;
            }
        }
    }
    cout << 0;
}