#include <bits/stdc++.h>

using namespace std;

int n;

int seq[100];
int arr[100];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> seq[i];
    }
    int now = 0;
    for(int i=0;i<n;i++){
        arr[now] = seq[i];
        seq[i] = 0;
        now = (now+arr[now])%n;
        
        // cout << now << '\n';
        while(arr[now] && i!=n-1){
            now = (now+1)%n;
        }
        // for(int j=0;j<n;j++){
        //     cout<< arr[j] << ' ';
        // }
        // cout << '\n';
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << ' ';
    }
}