#include <bits/stdc++.h>

using namespace std;

int c, l;

vector<pair<int, int>> vc;
int groupAble[100010];
map<int, vector<int>> suncream;

int cont[100010];
int used[100010];

int ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> c >> l;
    for(int i = 0; i < c; i++){
        int under, over; cin >> under >> over;
        vc.push_back({under, over});
    }
    for(int i = 0; i < l; i++){
        int val, thing; cin >> val >> thing;
        if(cont[val]){
            cont[val] += thing;
            continue;
        }
        cont[val] = thing;
        for(int j = 0; j < vc.size(); j++){
            auto [under, over] = vc[j];
            if(under <= val && val <= over){
                groupAble[j]++;
                suncream[val].push_back(j);
            }
        }
    }
    vector<pair<int,vector<int>>> vec(suncream.begin(), suncream.end());
    sort(vec.begin(), vec.end(), [&](auto a, auto b){
        return cont[a.first] > cont[b.first];
    });
    for(auto [element, group] : vec){
        sort(group.begin(),group.end(), [&](auto a, auto b){
            return groupAble[a] > groupAble[b];
        });
        while(cont[element] > 0){
            for(auto cow : group){
                if(!used[cow]){
                    used[cow] = 1;
                    ans++;
                    break;
                }
            }
            cont[element]--;
        }
        for(auto cow : group){
            if(!used[cow]){
               groupAble[cow]--;
            }
        }
    }
    cout << ans;
	return 0;
}