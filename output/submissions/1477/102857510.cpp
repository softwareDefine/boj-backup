#include <bits/stdc++.h>

using namespace std;

int n, m, l;

vector<int> vc;

int ans = 999999999;

void go(int now, int used, int dmax){
    if(used == m){
        if(now == n){
            ans = min(ans , dmax);
        }
        return;
    }
    int diff = vc[now+1] - vc[now], avail = m - used;
    for(int i = 1; i <= min(avail, diff); i++){
        go(now+1,used+i,max(dmax,(diff/(i+1) + ((diff%(i+1))?1:0))));
    }
}

int main() {
	cin >> n >> m >> l;
	vc.resize(n);
	for(auto &element : vc) {
		cin >> element;
	}
	vc.push_back(0);
	vc.push_back(l);
	sort(vc.begin(), vc.end());
	go(0, 0, 0);
	cout << ans;
	return 0;
}