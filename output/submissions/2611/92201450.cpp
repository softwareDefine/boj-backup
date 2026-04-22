#include <bits/stdc++.h>

using namespace std;

int n,m;
int inQueue[10010];
int before[10010];
int visited[10010];
vector<pair<int,int>> vc[10010];
queue<int> qu;
int cost[10010];
stack<int> st;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    cin >> m;
    for(int i=0;i<m;i++){
        int p,q,r;
        cin >> p >> q >> r;
        vc[p].push_back({q,r});
        inQueue[q]++;
    }
    qu.push(1);
    while(!qu.empty()){
        int now = qu.front();
        visited[now] = 1;
        qu.pop();
        for(auto &j : vc[now]){
            if(cost[j.first] < cost[now] + j.second){
                cost[j.first] = cost[now] + j.second;
                before[j.first] = now;
            }
            inQueue[j.first]--;
        }
        for(int i=1;i<=n;i++){
            if(!inQueue[i] && !visited[i]){
                qu.push(i);
            }
        }
    }
    cout << cost[1] << '\n';
    st.push(1);
    int cur = before[1];
    while (cur != 1)
    {
        st.push(cur);
        cur = before[cur];
    }
    st.push(1);
    while(!st.empty()){
        cout << st.top() << ' ';
        st.pop();
    }
}