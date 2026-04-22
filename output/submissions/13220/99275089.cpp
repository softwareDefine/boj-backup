#include <bits/stdc++.h>

using namespace std;

int n;

int arr[400000];
int brr[400000];
int pi[400000];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        arr[i+n] = arr[i];
    }
    for(int i=0;i<n;i++){
        cin >> brr[i];
    }
    int j = 0;
    for(int i=1;i<n;i++){
        while( j > 0 && brr[i] != brr[j]){
            j = pi[j-1];
        }
        if(brr[i] == brr[j]){
            pi[i] = ++j;
        }else{
            pi[i] = 0;
        }
    }
    j = 0;
    for(int i=0;i<2*n;i++){
        while( j > 0 && arr[i] != brr[j]){
            j = pi[j-1];
        }
        if(arr[i] == brr[j]){
            if(j == n-1){
                cout << "YES";
                return 0;
            }else{
                j++;
            }
        }
    }
    cout << "NO";
    return 0;
}