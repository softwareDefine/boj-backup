#include <bits/stdc++.h>

using namespace std;

int t;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while(t--){
        int x1, y1, x2, y2; int n;
        int ans = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        for(int i=0;i<n;i++){
            int cx, cy, r;
            cin >> cx >> cy >> r;
            if((cx-x1)*(cx-x1) + (cy-y1)*(cy-y1) < r*r || (cx-x2)*(cx-x2) + (cy-y2)*(cy-y2) < r*r){
                ans++;
            }
        }
        cout << ans << '\n';
    }
}