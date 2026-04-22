#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int n,k;
ll tree[800000];

ll change(int node,int start,int end,int pos,int val){
    if(pos < start || pos > end){
        return tree[node];
    }
    if(start == end){
        return tree[node] = val;
    }
    return tree[node] = change(node*2,start,(start+end)/2,pos,val) * change(node*2+1,(start+end)/2+1,end,pos,val);
}

ll cal(int node,int start,int end,int left,int right){
    if(right < start || left > end){
        return 1;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    return cal(node*2,start,(start+end)/2,left,right) * cal(node*2+1,(start+end)/2+1,end,left,right);
}

int main(){
    while(scanf("%d %d",&n,&k) != EOF){
        for(int i=0;i<800000;i++){
            tree[i] = 0;
        }
        for(int i=0;i<n;i++){
            int v;
            scanf(" %d",&v);
            if(v > 0){v = 1;}else if(v<0){v= -1;} 
            change(1,1,n,i+1,v);
        }
        while(k--){
            char dic; int i,v,j;
            scanf(" %c",&dic);
            if(dic == 'C'){
                scanf("%d %d",&i,&v);
                if(v > 0){v = 1;}else if(v<0){v= -1;} 
                change(1,1,n,i,v);
            }else{
                scanf("%d %d",&i,&j);
                ll ans = cal(1,1,n,i,j);
                if(ans > 0){ printf("+");}
                else if(ans < 0){printf("-");}
                else{printf("0");}
            }
        }
        printf("\n");
    }
}