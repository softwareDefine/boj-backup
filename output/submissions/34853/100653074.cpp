#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n, q;

vector<int> all;
vector<int> arr[200000];

bool finder(int idx, int a, int b, int c, int j){
    int stand = all[idx];
    int aBigger = upper_bound(arr[a].begin(),arr[a].end(),stand) - arr[a].begin();
    int bBigger = upper_bound(arr[b].begin(),arr[b].end(),stand) - arr[b].begin();
    int cBigger = upper_bound(arr[c].begin(),arr[c].end(),stand) - arr[c].begin();
    return (aBigger + bBigger + cBigger >= j);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 0;i < n ; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k;j++){
            int a;
            cin >> a;
            all.push_back(a);
            arr[i+1].push_back(a);
        }
        sort(arr[i+1].begin(),arr[i+1].end());
    }
    sort(all.begin(),all.end());
    while(q--){
        lint a, b, c, j;
        cin >> a >> b >> c >> j;
        lint left = 0, right = all.size()-1;
        while(left < right){
            lint mid = (left+right-1)/2;
            if(finder(mid, a, b, c, j)){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        cout << all[left] << '\n';
    }
}