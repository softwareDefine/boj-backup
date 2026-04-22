#include <bits/stdc++.h>

using namespace std;

int n, c;
int m;

struct node{
    int s;
    int e;
    int cost;
};

vector<node> vc;

int movement[3000];
int ans;

int main(){
    cin >> n >> c;
    cin >> m;
    for(int i=0;i<m;i++){
        int s,e,cost;
        cin >> s >> e >> cost;
        vc.push_back({s,e,cost});
    }
    sort(vc.begin(),vc.end(),[](auto a,auto b){
       if(a.e == b.e){return a.s > b.s;}
       return a.e < b.e; 
    });
    for(auto [s,e,cost] : vc){
        int mmx = 0;
        for(int i=s;i<e;i++){
            mmx = max(mmx,movement[i]);
        }
        ans += min(cost,(c-mmx));
        for(int i=s;i<e;i++){
            movement[i] += min(cost,(c-mmx));
        }
    }
    cout << ans;
}