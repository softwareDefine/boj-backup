#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint a,b,d,n;
lint arr[2000000];
lint sum[2000000];

int main(){
    cin >> a >> b >> d >> n;
    arr[0] = 1;
    sum[0] = 1;
    for(int i=1;i<=n;i++){
        arr[i] = ((i-a < 0 )?0:sum[i-a])%1000 - ((i-b < 0 )?0:sum[i-b])%1000;
        sum[i] = (sum[i]%1000 + (sum[i-1]%1000 + arr[i]%1000)%1000)%1000;
    }
    cout << (sum[n]%1000-((n-d<0)?0:sum[n-d])%1000)%1000;
}