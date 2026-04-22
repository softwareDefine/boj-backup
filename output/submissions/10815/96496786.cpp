#include <bits/stdc++.h>

using namespace std;

int n,m;
set<int> st;

int main(){
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        if(st.find(k) == st.end()){
            st.insert(k);
        }
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int g;
        cin >> g;
        if(st.find(g) != st.end()){
            cout << 1;
        }else{
            cout << 0;
        }
        cout << ' ';
    }
}