#define x first
#define y second
#include <bits/stdc++.h>

using lint = long long;
using namespace std;
using point = pair<lint, lint>;

int n;

vector<point> poly;
point mmn = {99999999,99999999};
int mmnidx;

vector<pair<lint, lint>> horizon;

stack<pair<lint,lint>> st;
lint outside,inside;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    poly.resize(n);
    for(int i = 0; i < n; i++){
        auto &[a,b] = poly[i];
        cin >> a >> b;
        if(mmn > poly[i]){
            mmn = poly[i];
            mmnidx = i;
        }
    }
    int number = 0;
    for(int i = mmnidx; i < n+mmnidx; i++){
        auto now = poly[i%n], next = poly[(i+1)%n];
        if(now.x == next.x){
            if(now.y < 0 && next.y > 0){
                ++number;
                horizon.push_back({now.x, number});
            }else if(now.y > 0 && next.y < 0){
                horizon.push_back({now.x, number});
            }
        }
    }
    sort(horizon.begin(), horizon.end());
    for(int i = 0; i < horizon.size(); i++){
        auto [coor, num] = horizon[i];
        if(st.empty()){
            st.push({num, i});
            continue;
        }
        if(st.top().first != num){
            st.push({num, i});
        }else{
            if(st.top().second + 1 == i){
                inside++;
            }
            if(st.size() == 1){
                outside++;
            }
            st.pop();
        }
    }
    cout << outside << ' ' << inside;
    return 0;
}