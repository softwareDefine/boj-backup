#define mod 1000000007
#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;
int arr[400000];
int brr[200000];
lint ptrSum, ptrTime = 1;
lint arrSum, arrTime = 1;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        arr[n+i] = arr[i];
        arrSum += arr[i];
        arrTime *= arr[i];
    }
    for(int i=0;i<n;i++){
        cin >> brr[i];
        ptrSum += brr[i];
        ptrTime *= brr[i];
    }
    for(int i=0;i<=n;i++){
        if(ptrSum == arrSum && ptrTime == arrTime){
            int j;
            for(j=0;j<n;j++){
                if(arr[i+j] != brr[j]){
                    j = 30000000;
                }
            }
            if(j != 30000001){
                cout << "YES";
                return 0;
            }
        }
        if(i!=n){
        arrSum+=arr[i+n];
        arrSum-=arr[i];
        arrTime *= arr[i+n];
        arrTime /= arr[i];
        }
    }
    cout << "NO";
}