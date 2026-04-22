#define height second
#define xcoor first
#include <bits/stdc++.h>

//using lint = long long;
using namespace std;

int n;

vector<pair<int, int>> vc;

int mmx, mmxidx;
int area;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, h; cin >> l >> h;
        vc.push_back({l, h});
    }
    sort(vc.begin(), vc.end());
    for(int i = 0; i < n; i++){
        auto [l, h] = vc[i];
        if(mmx <= h){
            mmx = h;
            mmxidx = i;
        }
    }
    mmx = 0; int mmxl = 0;
    for(int i = 0; i <= mmxidx; i++){
        if(mmx <= vc[i].height){
            if(i != 0){
                area += (vc[i].xcoor - mmxl)*mmx;
            }
            mmx = vc[i].height;
            mmxl = vc[i].xcoor;
        }
    }
    mmx = 0; mmxl = 0;
    for(int i = n-1; i >= mmxidx; i--){
        if(mmx <=vc[i].height){
            if(i != n-1){
                area += ( mmxl - vc[i].xcoor)*mmx;
            }
            mmx = vc[i].height;
            mmxl = vc[i].xcoor;
        }
    }
    cout << area + mmx;
	return 0;
}