#define fastio cin.tie(0)->sync_with_stdio(0)
#include <bits/stdc++.h>

using namespace std;

int n;
long long station[110000];
long long road[110000];
long long mmncost = 9999999999999;
long long tcost;

int main(){
    fastio;
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> road[i];
    }
    for(int i=0;i<n;i++){
        cin >> station[i];
    }
    for(int i=0;i<n-1;i++){
        mmncost = min(mmncost,station[i]);
        tcost += road[i]*mmncost;
    }
    cout << tcost;
}