#include<bits/stdc++.h>

using namespace std;

int n,l;
int arr[100010];
int nowtape,ans;

int main(){
    cin >> n >> l;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    nowtape = l;
    ans = 1;
    for(int i=1;i<n;i++){
        if(arr[i]-arr[i-1] < nowtape){
            nowtape -= (arr[i]-arr[i-1]);
        }else{
            ans++;
            nowtape = l;
        }
    }
    cout << ans;
}