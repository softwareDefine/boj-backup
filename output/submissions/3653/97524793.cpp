#include <bits/stdc++.h>

using namespace std;

int t;
int n,q;
int where[100000];
class seg{
    public:
    int tree[400000];
    int update(int left,int right,int pos,int node,int val){
        if(right < pos || left > pos){
            return tree[node];
        }
        if(left == right){
            return tree[node] = val; 
        }
        return tree[node] = update(left,(left+right)/2,pos,node*2,val) + update((left+right)/2+1,right,pos,node*2+1,val);
    }
    int query(int left,int right,int start,int end,int node){
        if(right < start || left > end){
            return 0;
        }
        if(start <= left && right <= end){
            return tree[node];
        }
        return query(left,(left+right)/2,start,end,node*2) + query((left+right)/2+1,right,start,end,node*2+1);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    seg myseg;
    cin >> t;
    while(t--){
        cin >> n >> q;
        memset(where,0,sizeof(where));
        memset(myseg.tree,0,sizeof(myseg.tree));
        for(int i=1;i<=n;i++){
            where[i] = n-i+1;
            myseg.update(1,100000,i,1,1);
        }
        for(int i=1;i<=q;i++){
            int e;
            cin >> e;
            cout << myseg.query(1,100000,where[e]+1,100000,1) << ' ';
            myseg.update(1,100000,where[e],1,0);
            where[e] = n+i;
            myseg.update(1,100000,where[e],1,1);
        }
        cout << '\n';
    }
}