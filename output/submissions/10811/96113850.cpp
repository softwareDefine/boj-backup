#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[200];
int brr[200];

int main(){
    for(int i=0;i<200;i++){
        arr[i] = i;
    }
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int s,e;
        cin >> s >> e;
        for(int j=s;j<=e;j++){
            brr[e-j+s]=arr[j];
        }
         for(int j=s;j<=e;j++){
            arr[j]=brr[j];
        }
    }
    for(int i=1;i<=n;i++){
        cout << arr[i] << ' '; 
    }
}