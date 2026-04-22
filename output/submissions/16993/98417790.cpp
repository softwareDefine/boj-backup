#include <bits/stdc++.h>

using lint = long long;
using namespace std;

struct range{
    lint all;
    lint left;
    lint right;
};

int n,m;

class segtree{
    public:
        lint arr[200000];
        lint sum[200000];
        range tree[800000];
        range query(int start,int end,int left,int right,int node){
            if(end < left || right < start){
                return {-100000000,-100000000,-100000000};
            }
            if(left <= start && end <= right){
                return tree[node]; 
            }
            range node1 = query(start,(start+end)/2,left,right,node*2);
            range node2 = query((start+end)/2+1,end,left,right,node*2+1);
            return {max(max(node1.all,node2.all),node1.right+node2.left),max(node1.left,sum[(start+end)/2]- sum[start-1] + node2.left),max(node2.right,sum[end]- sum[(start+end)/2] + node1.right)};
        }
        range update(int start,int end,int pos,int val,int node){
            if(pos < start || pos > end){
                return tree[node];
            }
            if(start == end){
                return tree[node] = {val,val,val};
            }
            range node1 = update(start,(start+end)/2,pos,val,node*2);
            range node2 = update((start+end)/2+1,end,pos,val,node*2+1);
            return tree[node] = {max(max(node1.all,node2.all),node1.right+node2.left),max(node1.left,sum[(start+end)/2]- sum[start-1] + node2.left),max(node2.right,sum[end]- sum[(start+end)/2] + node1.right)};
        }
};

segtree seg;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> seg.arr[i];
        seg.sum[i] = seg.sum[i-1] + seg.arr[i];
        seg.update(1,n,i,seg.arr[i],1); 
    }
    //seg.init(1,n,1);
    cin >> m;
    while(m--){
        int s,e;
        cin >> s >> e;
        cout << seg.query(1,n,s,e,1).all << '\n';
    }
}