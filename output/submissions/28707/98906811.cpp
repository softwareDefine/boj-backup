#include <bits/stdc++.h>

using namespace std;

int n,m;

typedef struct {
    int l;
    int r;
    int c;
}node;

map<vector<int>,int> mp;
vector<int> arr;
vector<node> q;
int mmn = 999999999;
void go(vector<int> vc,int cost){
    if(mp[vc] < cost){
        return;
    }
    int flag = 0;
    for(int i=0;i<vc.size()-1;i++){
        if(vc[i] > vc[i+1]){
            flag = 1; 
        }
    }
    if(!flag){
        mmn = min(mmn,cost);
        return;
    }
    for(auto & [l,r,c] : q){
        swap(vc[l-1],vc[r-1]);
        if(mp.find(vc) != mp.end()){
            mp[vc] = min(mp[vc],cost+c); 
        }else{
            mp[vc] = cost+c;
        }
        go(vc,cost+c);
        swap(vc[l-1],vc[r-1]);
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int l,r,c;
        cin >> l >> r >> c;
        q.push_back({l,r,c});
    }
    mp[arr] = 0;
    go(arr,0);
    if(mmn != 999999999){
    cout << mmn;
    }else{
        cout << -1;
    }
}