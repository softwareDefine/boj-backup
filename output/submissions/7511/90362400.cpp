#define fastio cin.tie(0)->sync_with_stdio(0)
#include <bits/stdc++.h>

using namespace std;

int t;
int parent[1100000];

int finder(int now){
    if(parent[now] == now){
        return now;
    }
    return parent[now] = finder(parent[now]);
}


int main(){
    fastio;
    cin >> t;
    int t, n, k, m, a, b,u,v;
    for(int i=1;i<=t;i++){
        cin >> n;
        for(int p=0;p<1100000;p++){
            parent[p] = p;
        }
        cin >> k;
        for(int j=0;j<k;j++){
            cin >> a >> b;
            if(finder(parent[a]) != finder(parent[b])){
                if(finder(parent[a]) > finder(parent[b])){
                    parent[a] = b;
                }else{
                    parent[b] = a;
                }
            }
        }
        cin >> m;
        cout << "Scenario " << i <<":\n"; 
        for(int l=0;l<m;l++){
            cin >> u >> v;
            if(finder(parent[u]) != finder(parent[v])){
                cout << 0 << '\n';
            }else{
                cout << 1 << '\n';
            }
        }
        cout << '\n';
    }
}