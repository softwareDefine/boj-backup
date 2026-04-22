#include<bits/stdc++.h>

using namespace std;

int n;
set<int> st;
int func[500];
vector<int> vc;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> func[i];
    }
    for(int i=1;i<=n;i++){
        int start = i;
        int now = start;
        st.clear();
        while(st.find(now)==st.end()){
            st.insert(now);
            now=func[now];
        }
        if(now == start){
            vc.push_back(now);
        }
    }
    cout << vc.size() << '\n';
    for(auto &i : vc){
        cout << i << '\n';
    }
}