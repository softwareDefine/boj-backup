#define SIZE 11000
#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int v, e;

vector<int> edge[SIZE];
int visited[SIZE];
int finished[SIZE];
int number = 0;

stack<int> st;

vector<vector<int>> groups;

int dfs(int now){
    visited[now] = ++number;
    st.push(now);
    
    int isPossible = visited[now];
    for(auto next : edge[now]){
        if(!visited[next]){
            isPossible = min(isPossible, dfs(next));   
        }else if(!finished[next]){
            isPossible = min(isPossible, visited[next]);
        }
    }
    
    if(isPossible == visited[now]){
        vector<int> tmp;
        while(1){
            tmp.push_back(st.top());
            finished[st.top()] = 1;
            if(st.top() == now){
                st.pop();
                break;
            }
            st.pop();
        }
        sort(tmp.begin(), tmp.end());
        groups.push_back(tmp);
    }
    return isPossible;
}
int main() {
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
    }
    for(int i = 1; i <= v; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    sort(groups.begin(),groups.end());
    cout << groups.size() << '\n';
    for(auto group : groups){
        for(auto element : group){
            cout << element << ' ';
        }
        cout << "-1\n";
    }
	return 0;
}