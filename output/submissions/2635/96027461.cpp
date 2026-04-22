#include <bits/stdc++.h>

using namespace std;

int n;
int mmx = 0;
int mmxarr[100000];
int arr[100000];
int start;

int main(){
    cin >> n;
    arr[1] = n;
    for(int i=1;i<=n;i++){
        arr[2] = i;
        start = 1;
        while(arr[start] - arr[start+1] >= 0){
            arr[start+2] = arr[start]-arr[start+1];
            start++;
        }
        if(mmx < start+1){
            mmx = start+1;
            for(int j=1;j<=start+1;j++){
                mmxarr[j] = arr[j]; 
            }
        }
    }
    cout << mmx << '\n';
    for(int j=1;j<=mmx;j++){
        cout << mmxarr[j] << ' ';
    }
}