#define fastio cin.tie(0)->sync_with_stdio(0)
#include <bits/stdc++.h>

using namespace std;
vector<int> vc;
pair<int,int> tree[11000];

void DnC(int now,int end){
    if(now > end){
        return;
    }
    if(now == end){  
        cout << vc[now] << '\n';
        return;
    }
    int start,start2;
    for(start=now+1;start<=end;start++){
        if(vc[start] < vc[now]){
            break;
        }
    }
    for(start2=now+1;start2<=end;start2++){
        if(vc[start2] > vc[now]){
            break;
        }
    }
    tree[now] = {start,start2};
    DnC(start,start2-1);
    DnC(start2,end);
    cout << vc[now] << '\n';
}

int main(){
    int t;
     while(scanf("%d",&t) != EOF){
         vc.push_back(t);
    }
    DnC(0,vc.size()-1);
}