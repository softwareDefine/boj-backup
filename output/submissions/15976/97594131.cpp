#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<pair<int,int>> arr;
vector<pair<int,int>> brr;
vector<pair<int,int>> sum;
int Size;
int s,e;
int ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i=0;i<n;i++){
		int idx,val;
		cin >> idx >> val;
		arr.push_back({idx,val});
		Size = max(Size,idx);
	}
	cin >> m;
	for(int i=0;i<m;i++){
		int idx,val;
		cin >> idx >> val;
		brr.push_back({idx,val});
		Size = max(Size,idx);
	}
	cin >> s >> e;
	sum.push_back({-1,0});
	for(int i=0;i<m;i++){
		if(i==0){sum.push_back(brr[i]); continue;}
		sum.push_back({brr[i].first,brr[i].second + sum[i].second});
	}
	for(auto element : arr){
	    int currentStart = s+element.first;
	    int currentEnd = e+element.first;
	    int start = max(currentStart,0);
	    int end = min(currentEnd,Size);
	    //cout << start << ' ' << end << ':';
	    auto left = lower_bound(sum.begin(), sum.end(),start, [](const pair<int,int>& p, int key){ return p.first < key; });
	    auto right = lower_bound(sum.begin(), sum.end(),end, [](const pair<int,int>& p, int key){ return p.first < key; });
	    --left;
	    if(right->first != end){
	        --right;
	    }
	    //cout << left - sum.begin() << ' ' << right - sum.begin() << '\n';
	    ans += element.second*(right->second  - left->second);
	    //cout << (right->second  - left->second) << '\n';
	}
	cout << ans;
}