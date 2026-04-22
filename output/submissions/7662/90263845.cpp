#define fastio cin.tie(0)->sync_with_stdio(0)
#include <bits/stdc++.h>

using namespace std;
multiset<int> mst;

int t;

int main(){
    fastio;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        while(k--){
            char task;
            int n;
            cin >> task >> n;
            if(task == 'I'){
                mst.insert(n);
            }else{
                if(!mst.empty()){
                if(n == 1){
                    mst.erase(*mst.rbegin());
                }else{
                    mst.erase(*mst.begin());
                }
            }
            }
        }
        if(!mst.size()){
            cout << "EMPTY" << '\n';
        }else{
            cout << *mst.rbegin() << ' ' << *mst.begin() << '\n';
        }
    }
}