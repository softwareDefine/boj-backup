#include <bits/stdc++.h>

using lint = long long;
using namespace std;

pair<pair<lint,lint>,lint> arr[400000];

struct range{
    lint all;
    lint left;
    lint right;
};

lint n;

vector<lint> vc;
vector<lint> vc2;

lint mmx;

class segtree{
    public:
        lint tree2[400000];
        range tree[400000];
        lint sum(int start,int end,int left,int right,int node){
            if(end < left || right < start){
                return 0;
            }
            if(left <= start && end <= right){
                return tree2[node]; 
            }
            return sum(start,(start+end)/2,left,right,node*2) + sum((start+end)/2+1,end,left,right,node*2+1);
        }
        range query(int start,int end,int left,int right,int node){
            if(end < left || right < start){
                return {-99999999999999,-99999999999999,-99999999999999};
            }
            if(left <= start && end <= right){
                return tree[node]; 
            }
            range node1 = query(start,(start+end)/2,left,right,node*2);
            range node2 = query((start+end)/2+1,end,left,right,node*2+1);
            return {max(max(node1.all,node2.all),node1.right+node2.left),max(node1.left,sum(0,30000,start,(start+end)/2,1) + node2.left),max(node2.right,sum(0,30000,(start+end)/2+1,end,1) + node1.right)};
        }
        range update(int start,int end,int pos,lint val,int node){
            if(pos < start || pos > end){
                return tree[node];
            }
            if(start == end){
                return tree[node] = {tree[node].all + val,tree[node].all +val,tree[node].all +val};
            }
            range node1 = update(start,(start+end)/2,pos,val,node*2);
            range node2 = update((start+end)/2+1,end,pos,val,node*2+1);
            return tree[node] = {max(max(node1.all,node2.all),node1.right+node2.left),max(node1.left,sum(0,30000,start,(start+end)/2,1) + node2.left),max(node2.right,sum(0,30000,(start+end)/2+1,end,1) + node1.right)};
        }
        lint updatesum(int start,int end,int pos,lint val,int node){
            if(pos < start || pos > end){
                return tree2[node];
            }
            if(start == end){
                return tree2[node] += val;
            }
            return tree2[node] = updatesum(start,(start+end)/2,pos,val,node*2) + updatesum((start+end)/2+1,end,pos,val,node*2+1);
        }
};

segtree seg;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
        vc.push_back(arr[i].first.first);
        vc2.push_back(arr[i].first.second);
    }
    sort(vc.begin(),vc.end());
    sort(vc2.begin(),vc2.end());
    vc.erase(unique(vc.begin(),vc.end()),vc.end());
    vc2.erase(unique(vc2.begin(),vc2.end()),vc2.end());
    for (int i = 0; i < n; i++) {
		arr[i].first.first = lower_bound(vc.begin(), vc.end(), arr[i].first.first) - vc.begin();
		arr[i].first.second = lower_bound(vc2.begin(), vc2.end(), arr[i].first.second) - vc2.begin();
	}
	sort(arr,arr+n,[](auto a,auto b){
	   if(a.first.second == b.first.second) {return a.first.first < b.first.first;}
	   return a.first.second < b.first.second;
	});
	for(int i=n;i<40000;i++){
	    arr[i].first.second = -1;
	}
    for(int i=0;i<n;i++){
        for(int j=0;j<40000;j++){
            seg.tree[j] = {0,0,0};
            seg.tree2[j] = 0;
            //seg.updatesum(0,10000,j,0,1);
            //seg.update(0,10000,j,0,1);
        }
        for(int j=i;j<n;j++){
            seg.updatesum(0,30000,arr[j].first.first,arr[j].second,1);
            seg.update(0,30000,arr[j].first.first,arr[j].second,1);
            
            if(arr[j].first.second != arr[j+1].first.second){
                mmx = max(mmx,seg.query(0,30000,0,30000,1).all);
            }
        }
        while(arr[i].first.second == arr[i+1].first.second){
            i++;
        }
    }
    cout << mmx;
}