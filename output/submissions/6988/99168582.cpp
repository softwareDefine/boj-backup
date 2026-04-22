#include <bits/stdc++.h>

using lint = long long;
using namespace std;

lint n;
lint arr[4000];
vector<pair<lint,pair<lint,lint>>> dp[4000];
lint mmx;

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	for(int i=0; i<n; i++) {
		for(int j=n; j>i; j--) {
			lint beforeN = 1;
			lint beforeT = arr[i];
			auto it = lower_bound(dp[i].begin(),dp[i].end(),arr[j]-arr[i],[](const pair<int,pair<int,int>>& elem, int key) {
				return elem.first < key;
			});
			if(it != dp[i].end() && (*it).first == arr[j]-arr[i]) {
				beforeN = (*it).second.first;
				beforeT = (*it).second.second;
			}
			dp[j].push_back({arr[j]-arr[i],{beforeN+1,beforeT+arr[j]}});
			if(beforeN+1 >= 3) {
				mmx = max(mmx,arr[j]+beforeT);
			}
		}
	}
	cout << mmx;
}