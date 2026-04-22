#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint a,b,d,n;
lint arr[1500000];
lint sum[1500000];

int main(){
    cin >> a >> b >> d >> n;
    arr[0] = 1;
    sum[0] = 1;
    for(int i=1;i<=n;i++){
        arr[i] = (((i-a < 0 )?0:sum[i-a]) - ((i-b < 0 )?0:sum[i-b]))%1000;
        sum[i] += (sum[i-1] + arr[i])%1000;
    }
    cout << (sum[n]-sum[n-d])%1000;
}