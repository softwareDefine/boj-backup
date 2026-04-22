#include<bits/stdc++.h>

using namespace std;

int n,m;

int sixmmn = 1000, onemmn = 1000;
int ans = 1000;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        sixmmn = min(a,sixmmn);
        onemmn = min(b,onemmn);
    }
    ans = min(((n/6) * sixmmn) + (onemmn* (n%6)),(((n/6)+1) * sixmmn));
    cout << ans;
}