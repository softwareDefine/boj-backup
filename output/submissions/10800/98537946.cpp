#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n;

pair<pair<lint,lint>,lint> arr[300000];
lint color[300000];
lint big[300000];
lint ans[300000];
lint bigandcolor[3000][3000];
lint total;

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
        big[arr[i].first.first] += arr[i].first.first;
        bigandcolor[arr[i].first.first][arr[i].first.second] += arr[i].first.first;
        ans[arr[i+1].second] = total - color[arr[i+1].first.second] - big[arr[i+1].first.first] + bigandcolor[arr[i+1].first.first][arr[i+1].first.second];
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << '\n';
    }
}