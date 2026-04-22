#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n,m;
vector<pair<int,int>> vc;
stack<pair<int,int>> st;
int ans ;
int main(){
    cin >> n >> m;
    ans = m;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        if(a > b){
            vc.push_back({b,1});
            vc.push_back({a,-1});
            // 같은 위치에서 1,-1 우선순위 고려
        }
    }
    sort(vc.begin(),vc.end(), [&](auto a,auto b){
        return a.first < b.first;
    });
    for(auto &i : vc){
        if(st.empty()){
            st.push({i.first,1});
            continue;
        }
        if(i.second == -1){
            int top = st.top().first;
            st.pop();
            if(st.empty()){
                ans += 2*(i.first - top);
            }
        }else{
            st.push({i.first,1});
        }
    }
    cout << ans;
}