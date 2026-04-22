#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll t;
int aSize,bSize;

int arr[2000];
int brr[2000];

ll sumarr[2000];
ll sumbrr[2000];

map<ll,int> mp;

ll sum = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    cin >> aSize;
    for(int i=0;i<aSize;i++){
        cin >> arr[i];
    }
    cin >> bSize;
    for(int i=0;i<bSize;i++){
        cin >> brr[i];
    }
    for(int i=1;i<=aSize;i++){
        sumarr[i] = sumarr[i-1] + arr[i-1];
    }
    for(int i=1;i<=aSize;i++){
        for(int j=1;j<=i;j++){
            mp[sumarr[i] - sumarr[j-1]]++;
        }
    }
    for(int i=1;i<=bSize;i++){
        sumbrr[i] = sumbrr[i-1] + brr[i-1]; 
    }
    for(int i=1;i<=bSize;i++){
        for(int j=1;j<=i;j++){
            ll nowCal = sumbrr[i] - sumbrr[j-1];
            sum += mp[t-nowCal];
        }
    }
    cout << sum;
    return 0;
}