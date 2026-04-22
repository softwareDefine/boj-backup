#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n, k;
lint current[4];

vector<lint> arr[4];
int point[4];

vector<pair<char,lint>> ans;

int main(){
    cin >> n >> k;
    for(int i = 0; i < 4; i++){
        cin >> current[i];
    }
    for(int i = 0; i < n; i++){
        char choice; lint dx;
        cin >> choice >> dx;
        arr[choice-'A'].push_back(dx);
    }
    for(int i = 0; i < 4; i++){
        sort(arr[i].begin(),arr[i].end(), [&](auto a, auto b){
            return a > b;
        });
    }
    for(int i = 0; i < k; i++){
        lint next[4] = {0, };
        for(int chose = 0; chose < 4; chose++){
            lint adding = ((point[chose] < arr[chose].size())? arr[chose][point[chose]] : 0);
            switch(chose){
                case 0:{
                    next[chose] = adding*current[1]*current[2]*current[3];
                    break;
                }
                case 1:{
                    next[chose] = adding*current[0]*current[2]*current[3];
                    break;
                }
                case 2:{
                    next[chose] = adding*current[0]*current[1]*current[3];
                    break;
                }
                case 3:{
                    next[chose] = adding*current[1]*current[2]*current[0];
                    break;
                }
            }
        }
        lint mmx = 0; int mmxidx = 0;
        for(int i = 0; i < 4; i++){
            if(mmx < next[i]){
                mmx = next[i];
                mmxidx = i;
            }
        }
        ans.push_back({mmxidx+'A', arr[mmxidx][point[mmxidx]]});
        current[mmxidx] += arr[mmxidx][point[mmxidx]++];
    }
    for(auto [a, b] : ans){
        cout << a << ' ' << b << '\n';
    }
}