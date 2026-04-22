#include <bits/stdc++.h>

using namespace std;

int n, k;
int cnt;

int parent[200000];
int color[200000];
int rev[200000];
int visited[200000];
set<int> st;
int now;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    parent[0] = -1;
    while(k--){
        int r, a, b, c;
        cin >> r;
        switch(r){
            case 1:
                cin >> a >> b >> c;
                now = a;
                visited[now] = k;
                rev[parent[now]] = now;
                for(int i=0;i<1000 && parent[now] != -1;i++){
                    now = parent[now];
                    rev[parent[now]] = now; 
                    visited[now] = k;
                }
                now = b;
                if(visited[now] == k){
                    while(now != a){
                        now = rev[now];
                        color[now] = c;
                    }
                    break;
                }
                visited[now] = k;
                for(int i=0;i<1000 && parent[now] != -1;i++){
                    color[now] = c;
                    now = parent[now];
                    if(visited[now] == k){
                        while(now != a){
                            now = rev[now];
                            color[now] = c;
                        }
                        break;
                    }
                    visited[now] = k;
                }
                break;
            case 2:
                cin >> a >> b;
                parent[a] = b;
                break;
            case 3:
                cin >> a >> b;
                now = a;
                visited[now] = k;
                rev[parent[now]] = now;
                for(int i=0;i<1000 && parent[now] != -1;i++){
                    now = parent[now];
                    visited[now] = k;
                    rev[parent[now]] = now; 
                }
                now = b;
                if(visited[now] == k){
                    while(now != a){
                        now = rev[now];
                        st.insert(color[now]);
                    }
                    cout << st.size() << '\n';
                    st.clear();
                    break;
                }
                visited[now] = k;
                for(int i=0;i<1000 && parent[now] != -1;i++){
                    st.insert(color[now]);
                    now = parent[now];
                    if(visited[now] == k){
                        while(now != a){
                            now = rev[now];
                            st.insert(color[now]);
                        }
                        cout << st.size() << '\n';
                        st.clear();
                        break;
                    }
                    visited[now] = k;
                }
                break;
        }
    }
}