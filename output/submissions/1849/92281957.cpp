#include <bits/stdc++.h>

using namespace std;

int n;
int tree[400000];
int arr[200000];
int ans[200000];

int query(int node,int start,int end,int left,int right){
    if(right < start || end < left){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    int mid = (start+end)/2;
    return query(node*2,start,mid,left,right) + query(node*2+1,mid+1,end,left,right);
}

int update(int node,int start,int end,int pos){
    if(pos < start || pos > end){
        return tree[node];
    }
    if(start == end){
        return tree[node] = 1;
    }
    int mid = (start+end)/2;
    return tree[node] = update(node*2,start,mid,pos) + update(node*2+1,mid+1,end,pos);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    for(int i=1;i<=n-1;i++){
        int start = 1;
        int end = n;
        int mid;
        while(start <= end){
            mid = (start+end)/2;
            int tans = query(1,1,n,1,mid-1);
            if(mid-1 - tans > arr[i]){
                end = mid-1;
            }else if(mid-1 - tans < arr[i]){
                start = mid+1;
            }else{
                break;
            }
        }
        ans[mid] = i;
        update(1,1,n,mid);
    }
    for(int i=1;i<=n;i++){
        if(!ans[i]){ ans[i]= n;}
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << '\n';
    }
}