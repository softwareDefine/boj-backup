#include <bits/stdc++.h>

using namespace std;

int visited[100010];
int x[100010];
int t[100010];

int n;
int mmx;
int mmxsum;
int before;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    for(int i=0;i<n;i++){
        cin >> t[i];
    }
    // 내현재시간간
    mmx = max(t[n-1],x[n-1]);
    before = x[n-1];
    mmxsum += mmx;
    for(int i=n-2;i>=0;i--){
        if(x[i] < t[i]){
            mmx += max(t[i]-mmx,before-x[i]);
            before = x[i];
        }
    }
    mmx += before;
    cout << mmx;
}