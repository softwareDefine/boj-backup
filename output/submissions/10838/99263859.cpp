#include <bits/stdc++.h>

using namespace std;

int n, k;

int parent[200000];
int color[200000];
int rev[200000];
map<int,int> visited;
set<int> st;
int now;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    parent[0] = -1;
    while(k--){
        int r,a,b,c;
        cin >> r;
        switch(r){
            case 1:
                cin >> a >> b >> c;
                now = a;
                visited[now] = 1;
                rev[parent[now]] = now;
                for(int i=0;i<1000 && parent[now] != -1;i++){
                    now = parent[now];
                    rev[parent[now]] = now; 
                    visited[now] = 1;
                }
                now = b;
                if(visited[now]){
                    while(now != a){
                        now = rev[now];
                        color[now] = c;
                    }
                    visited.clear();
                    break;
                }
                visited[now] = 1;
                for(int i=0;i<1000 && parent[now] != -1;i++){
                    color[now] = c;
                    now = parent[now];
                    if(visited[now]){
                        while(now != a){
                            now = rev[now];
                            color[now] = c;
                        }
                        visited.clear();
                        break;
                    }
                    visited[now] = 1;
                }
                break;
            case 2:
                cin >> a >> b;
                parent[a] = b;
                break;
            case 3:
                cin >> a >> b;
                now = a;
                visited[now] = 1;
                rev[parent[now]] = now;
                for(int i=0;i<1000 && parent[now] != -1;i++){
                    now = parent[now];
                    visited[now] = 1;
                    rev[parent[now]] = now; 
                }
                now = b;
                if(visited[now]){
                    while(now != a){
                        now = rev[now];
                        st.insert(color[now]);
                    }
                    cout << st.size() << '\n';
                    visited.clear();
                    st.clear();
                    break;
                }
                visited[now] = 1;
                for(int i=0;i<1000 && parent[now] != -1;i++){
                    st.insert(color[now]);
                    now = parent[now];
                    if(visited[now]){
                        while(now != a){
                            now = rev[now];
                            st.insert(color[now]);
                        }
                        cout << st.size() << '\n';
                        visited.clear();
                        st.clear();
                        break;
                    }
                    visited[now] = 1;
                }
                break;
        }
    }
}