#include <bits/stdc++.h>

using namespace std;

int n;

pair<pair<int,int>,int> arr[300000];
int color[300000];
int ans[300000];
int total;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i].first.second >> arr[i].first.first;
        arr[i].second = i;
    }
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++){
        total+=arr[i].first.first;
        color[arr[i].first.second] += arr[i].first.first;
        ans[arr[i+1].second] = total - color[arr[i+1].first.second];
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << '\n';
    }
}