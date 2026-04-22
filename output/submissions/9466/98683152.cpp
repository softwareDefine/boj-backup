#include <bits/stdc++.h>

using namespace std;

int t;
int arr[200000];
int visited[200000];
int ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while(t--){
        int n;
        ans = 0;
        int cnt = 1;
        memset(arr,0,sizeof(arr));
        memset(visited,0,sizeof(visited));
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> arr[i];
        }
        for(int i=1;i<=n;i++){
            int now = i;
            if(visited[i]){continue;}
            while(!(visited[now])){
                visited[now] = cnt++;
                now = arr[now];
            }
            if(visited[i] > visited[now]){
                continue;
            }else{
                //cout << i <<" cnt : " << cnt -visited[now] << '\n';
                ans += cnt -visited[now];
            }
        }
        cout << n-ans << '\n';
    }
}