#include<bits/stdc++.h>

using namespace std;

int n,l,h;
int mmx=-99999999;
vector<pair<int,int>> vc;
vector<pair<int,int>> cord;

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin >> n >> l >> h;
	for(int i=1; i<=h; i++) {
		int a,b;
		cin >> a >> b;
		cord.push_back({a,b});
	}
	for(int i=1; i<l/2; i++) {
		vc.push_back({i,l/2-i});
	}
	for(auto square : vc) {
		for(auto point : cord) {
		    for(int i=0;i<=square.first;i++){
		        for(int j=0;j<=square.second;j++){
		            int cnt = 0;
		            if(point.first-i >= 1 && (square.first-i) +point.first <= n && point.second-j >= 1 && (square.second-j) +point.second <= n ){}else{continue;}
		            for(auto element : cord) {
        				if(point.first-element.first <= i  && point.first-element.first >= i-square.first && point.second-element.second <= j && point.second-element.second >= j-square.second) {
        					cnt++;
        				}
        			}
		            mmx=max(mmx,cnt);
		        }
		    }
		}
	}
	cout << mmx;
}