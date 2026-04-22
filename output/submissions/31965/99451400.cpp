#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n, q;

vector<lint> cord;
vector<pair<lint,lint>> dist;
lint leftsum = 0;
lint sum = 0;

lint totaldist(lint sidx,lint eidx,lint i){
    return dist[i].second - dist[eidx].second - (n-eidx-1)*(cord[eidx]-cord[i]) + \
    dist[i].first - dist[sidx].first - (sidx)*(cord[i]-cord[sidx]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for(int i=0;i<n;i++){
        lint x;
        cin >> x;
        cord.push_back(x);
        sum += (cord[i]-cord[0]);
    }
    cord.push_back(20000000000);
    for(int i=0;i<n;i++){
        dist.push_back({leftsum, sum});
        sum -= (cord[i+1]-cord[i])*(n-i-1);
        leftsum += (cord[i+1]-cord[i])*(i+1);
    }
    // for(auto [left,right] : dist){
    //     cout << left << ' ' << right << '\n';
    // }
    while(q--){
        lint s, e;
        cin >> s >> e;
        lint sidx = lower_bound(cord.begin(), cord.end(), s) - cord.begin();
        lint eidx = upper_bound(cord.begin(), cord.end(), e) - cord.begin();
        //cout << eidx-1 << ' ' << sidx << '\n';
        if(eidx-1 < sidx){ cout << 0 << '\n'; continue; } eidx -= 1;
        lint mmx = max(dist[sidx].second - dist[eidx].second - (n-eidx-1)*(cord[eidx]-cord[sidx]), \
        dist[eidx].first - dist[sidx].first - (sidx)*(cord[eidx]-cord[sidx]));
        lint mmn = min(dist[sidx].second - dist[eidx].second - (n-eidx-1)*(cord[eidx]-cord[sidx]), \
        dist[eidx].first - dist[sidx].first - (sidx)*(cord[eidx]-cord[sidx]));
        lint left = sidx, right = eidx-1, mid = sidx;
        while(left < right){
            mid = (left+right)/2;
            if(totaldist(sidx,eidx,mid+1) - totaldist(sidx,eidx,mid) < 0){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        mmn = min(mmn,totaldist(sidx,eidx,left));
        cout << mmx - mmn << '\n';    
    }
}