#include <bits/stdc++.h>

using namespace std;

int c, l;

vector<pair<int, int>> vc;
int groupAble[100010];
map<int, int> suncream;

int cont[100010];
int used[100010];

int ans;

priority_queue<pair<int,int>> pq;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> c >> l;
    for(int i = 0; i < c; i++){
        int under, over; cin >> under >> over;
        vc.push_back({under, over});
    }
    sort(vc.begin(),vc.end());
    for(int i = 0; i < l; i++){
        int val, thing; cin >> val >> thing;
        suncream[val] += thing;
    }
    for(auto [spf, num] : suncream){
        for(int i = 0; i < vc.size(); i++){
            auto [under, over] = vc[i];
            if(under <= spf && spf <= over){
                pq.push({-over, i});
            }
        }
        while(!pq.empty() && num > 0){
            if(!used[pq.top().second]){
                used[pq.top().second] = 1;
                num--;
                ans++;
            }
            pq.pop();
        }
        while(!pq.empty()){ pq.pop(); }
    }
    cout << ans;
	return 0;
}