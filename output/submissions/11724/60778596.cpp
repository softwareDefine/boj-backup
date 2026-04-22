#include <iostream>
#include <vector>


using namespace std;

vector<int> arr[1001];
int visited[1001];
int n , m;

void dfs(int now){
    visited[now]=1;
    int a = arr[now].size();
    for(int i=0;i<a;i++){
       if(!visited[arr[now][i]]){
        dfs(arr[now][i]);
       }
    }
}

int main()
{
    cin >>n >> m;
    for(int j=0;j<m;j++){
        int a ,b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    int cnt =0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    cout <<  cnt;
    return 0;
}