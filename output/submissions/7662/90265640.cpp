#define fastio cin.tie(0)->sync_with_stdio(0)
#include <bits/stdc++.h>

using namespace std;
multiset<long long> mst;

int t;

int main(){
    fastio;
    cin >> t;
    while(t--){
        mst.clear();
        int k;
        cin >> k;
        while(k--){
            char task;
            long long n;
            cin >> task >> n;
            if(task == 'I'){
                mst.insert(n);
            }else{
                if(!mst.empty()){
                if(n == 1){
                    mst.erase(mst.find(*mst.rbegin()));
                }else{
                    mst.erase(mst.find(*mst.begin()));
                }
            }
            }
        }
        if(mst.empty()){
            cout << "EMPTY" << '\n';
        }else{
            cout << *mst.rbegin() << ' ' << *mst.begin() << '\n';
        }
    }
}