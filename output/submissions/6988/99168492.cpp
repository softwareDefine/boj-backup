#include <bits/stdc++.h>

using namespace std;

int n;
int arr[4000];
vector<pair<int,pair<int,int>>> dp[4000];
int mmx;

int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	for(int i=0; i<n; i++) {
	    reverse(dp[i].begin(),dp[i].end());
		for(int j=i+1; j<n; j++) {
			int beforeN = 1;
			int beforeT = arr[i];
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