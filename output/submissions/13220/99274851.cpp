#define mod 1000000007
#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n;
int arr[400000];
int brr[200000];
lint tenPow[100000];
lint ptrSum, ptrTime = 0;
lint arrSum, arrTime = 0;

int main(){
    tenPow[0] = 1;
    for(int i=1;i<=100000;i++){
        tenPow[i] = tenPow[i-1]*10;
    }
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        arr[n+i] = arr[i];
        arrSum += arr[i];
        arrTime += (arr[i]%10)*tenPow[i];
    }
    for(int i=0;i<n;i++){
        cin >> brr[i];
        ptrSum += brr[i];
        ptrTime += (brr[i]%10)*tenPow[i];
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
        arrTime /= 10;
        arrTime += (arr[i+n]%10)*tenPow[n-1];
        }
    }
    cout << "NO";
}