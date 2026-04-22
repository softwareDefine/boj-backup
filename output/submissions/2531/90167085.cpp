#define fastio cin.tie(0)->sync_with_stdio(false)
#include<iostream>
#include<set>

using namespace std;

int n,d,k,c2;
int arr[70000];
int cnt,mmx;
int c[4100];

int main(){
    fastio;
    cin >> n >> d >> k >> c2;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        arr[n+i] = arr[i];
    }
    c[c2]++;
    cnt++;
    for(int i=1;i<=k;i++){
        if(!c[arr[i]]++){
            cnt++;
        }
    }
    mmx = max(cnt,mmx);
    for(int i=k+1;i<=n+k;i++){
        if(!--c[arr[i-k]]){
            cnt--;
        }
        if(!c[arr[i]]++){
            cnt++;
        }
        mmx = max(cnt,mmx);
    }
    cout << mmx;
}