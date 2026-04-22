#include <bits/stdc++.h>

using namespace std;

int n;
int arr[200];
int counter[2000];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        counter[arr[i]]++;
    }
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++){
        if(arr[i]+1 == arr[i+1]){
            if(arr[i+1] == arr[n-1]){
                int now = i;
                while(now>=0 && arr[now] == arr[i]){
                    now--;
                }
                now++;
                swap(arr[now],arr[i+1]);
            }else{
                int now = i+1;
                while(now<=n-1 && arr[now] == arr[i+1]){
                    now++;
                }
                swap(arr[now],arr[i+1]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << arr[i] <<' ';
    }
}