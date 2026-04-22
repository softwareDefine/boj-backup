#include <bits/stdc++.h>

using namespace std;

typedef struct line{
    int x1;
    int x2;
    int y;
    int idx;
}line;

int n,q;
vector<line> vc;

int possible[200000];
int revpossible[200000];
int seq[200000];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        int x1,x2,y;
        cin >> x1 >> x2 >> y;
        vc.push_back({x1,x2,y,i});
    }
    sort(vc.begin(),vc.end(),[](const line& a, const line& b){
        if (a.y != b.y)   return a.y < b.y;
        if (a.x1 != b.x1) return a.x1 < b.x1;
        return a.x2 < b.x2;
    });
    int start = vc[0].idx;
    possible[start] = start;
    //for(int i=0;i<vc.size();i++){ seq[vc[i].idx] = i;}
    for(int i=0;i<vc.size()-1;i++){
        line now = vc[i];
        line next = vc[i+1];
        if(now.x2 >= next.x1){
            possible[next.idx] = start; 
        }else{
            start = next.idx;
            possible[next.idx] = start;
        }
    }
    /*reverse(vc.begin(),vc.end());
    start = vc[0].idx;
    revpossible[start] = start;
    for(int i=0;i<vc.size()-1;i++){
        line now = vc[i];
        line next = vc[i+1];
        if(now.x2 >= next.x1){
            revpossible[next.idx] = start; 
        }else{
            start = next.idx;
            revpossible[next.idx] = start;
        }
    }
    reverse(vc.begin(),vc.end());*/
    while(q--){
        int s,e;
        cin >> s >> e;
        if(possible[s] == possible[e]){
            cout << 1 << '\n';
        }else{
            cout << 0 << '\n';
        }
    }
}