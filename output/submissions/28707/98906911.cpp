#include <bits/stdc++.h>

using lint = long long;
using namespace std;

int n,m;

typedef struct {
	int l;
	int r;
	int c;
} node;

map<vector<int>,int> mp;
vector<int> arr;
vector<node> q;
int mmn = 999999999;
queue<pair<vector<int>,int>> qu;

void bfs(vector<int> vc,int cost) {
	mp[vc] = cost;
	qu.push({vc,cost});
	while(!qu.empty()) {
		auto nowSeq = qu.front().first;
		int nowCost = qu.front().second;
		int flag = 0;
		for(int i=0; i<nowSeq.size()-1; i++) {
			if(nowSeq[i] > nowSeq[i+1]) {
				flag = 1;
				break;
			}
		}
		if(!flag) {
			mmn = min(mmn,nowCost);
		qu.pop();
			continue;
		}
		qu.pop();
		for(auto &[l,r,c] : q) {
			swap(nowSeq[l-1],nowSeq[r-1]);
			if(mp.find(nowSeq) == mp.end() || mp[nowSeq] > nowCost+c) {
				mp[nowSeq] = nowCost+c;
				qu.push({nowSeq,nowCost+c});
			}
			swap(nowSeq[l-1],nowSeq[r-1]);
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i=0; i<n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	cin >> m;
	for(int i=0; i<m; i++) {
		int l,r,c;
		cin >> l >> r >> c;
		q.push_back({l,r,c});
	}
	bfs(arr,0);
	if(mmn != 999999999) {
		cout << mmn;
	} else {
		cout << -1;
	}
}