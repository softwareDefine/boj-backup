#include <iostream>

using ll = long long;
using namespace std;

ll arr[100010];
ll chk[100010];
ll dp[100010];
int n;

struct seg{
    ll tree[400010];
    void update(int node,int left,int right,int pos){
        if(pos < left || pos > right){
            return;
        }
        if(left == right){
            tree[node] += 1;
            return;
        }
        ll mid = (left+right)/2;
        update(node*2,left,mid,pos);
        update(node*2+1,mid+1,right,pos);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    ll query(int node,int left,int right,int start,int end){
        if(right < start || end < left){
            return 0;
        }
        if(left <= start && end <= right){
            return tree[node];
        }
        ll mid = (start+end)/2;
        return query(node*2,left,right,start,mid) + query(node*2+1,left,right,mid+1,end);
    }
};

seg s1;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        dp[arr[i]] += s1.query(1,arr[i]+1,n,0,n);
        s1.update(1,0,n,arr[i]);
    }
    for(int i=0;i<n;i++){
        if(i-1 >= 0){
            chk[i] += dp[i-1];
            chk[i] += chk[i-1];
        }
        cout << chk[i] << '\n';
    }
}
