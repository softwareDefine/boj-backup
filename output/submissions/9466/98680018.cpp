#include <bits/stdc++.h>

using namespace std;


int t;
int parent[200000];
int arr[200000];
int ans;
set<int> st;

int find(int now){
    if(parent[now] == now){
        return now;
    }
    return parent[now] = find(parent[now]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while(t--){
        int n;
        ans = 0;
        iota(parent,parent+200000,0);
        memset(arr,0,sizeof(arr));
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> arr[i];
        }
        for(int i=1;i<=n;i++){
            int flag = 0;
            int now = arr[i];
            int cnt = 1;
            if(parent[i] != i){continue;}
            while(now != i){
                now = arr[now];
                if(now != i && st.find(now) != st.end()){
                    flag =1;
                    break;
                }
                st.insert(now);
                //cout << now << ' ';
                cnt++;
            }
            if(flag){
                cnt =0;
            }else{
                //cout << cnt;
                ans += cnt;
                now = arr[i];
                while(now != i){
                    parent[find(now)] = i;
                    now = arr[now];
                }
            }
        }
        st.clear();
        cout << n-ans << '\n';
    }
}