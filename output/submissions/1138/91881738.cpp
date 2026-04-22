#include<bits/stdc++.h>

using namespace std;

int n;
int ans[100];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int loc;
        cin >> loc;
        int cnt = 0;
        for(int j=0;j<=(loc+cnt);j++){
            if(ans[j] && ans[j] < (i+1)){
                cnt++;
            }
        }
        ans[loc+cnt] = i+1;
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << ' ';
    }
}