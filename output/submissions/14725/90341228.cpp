#define fastio cin.tie(0)->sync_with_stdio(0)
#include <bits/stdc++.h>

using namespace std;

int n;

struct node{
    string myval;
    vector<node> children;
};

vector<string> vc;

void add(int depth, node &where){
    if(depth == vc.size()){
        return;
    }
    int find = -1;
    for(int i=0;i<where.children.size();i++){
        if(where.children[i].myval == vc[depth]){
            find = i;
        }
    }
    if(find == -1){
        node y;
        y.myval = vc[depth];
        where.children.push_back(y);
        add(depth+1,where.children[where.children.size()-1]);
        return;
    }
    add(depth+1,where.children[find]);
}

bool cal(node a, node b){
    return a.myval < b.myval;
}

void dfs(int depth,node where){
    sort(where.children.begin(),where.children.end(),cal);
    if(depth != 0){
        for(int i=0;i<depth-1;i++){
            cout << "--";
        }
        cout << where.myval <<'\n';
    }
    for(int i=0;i<where.children.size();i++){
            dfs(depth+1,where.children[i]);
    }
}

int main(){
    cin >> n;
    node root;
    root.myval = "";
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        while(!vc.empty()){
            vc.pop_back();
        }
        for(int j=0;j<k;j++){
            string tmp;
            cin >> tmp;
            vc.push_back(tmp);
        }
        add(0,root);
    }
    dfs(0,root);
}