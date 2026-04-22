#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<pair<long long ,long long >> arr;
vector<pair<long long ,long long >> brr;
vector<pair<long long ,long long >> sum;
long long  Size;
long long  s,e;
long long ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i=0;i<n;i++){
		long long  idx,val;
		cin >> idx >> val;
		arr.push_back({idx,val});
		Size = max(Size,idx);
	}
	cin >> m;
	for(int i=0;i<m;i++){
		long long  idx,val;
		cin >> idx >> val;
		brr.push_back({idx,val});
		Size = max(Size,idx);
	}
	cin >> s >> e;
	sum.push_back({-1LL,0LL});
	for(int i=0;i<m;i++){
		if(i==0){sum.push_back(brr[i]); continue;}
		sum.push_back({brr[i].first,brr[i].second + sum[i].second});
	}
	for(auto element : arr){
	    long long currentStart = s+element.first;
	    long long currentEnd = e+element.first;
	    long long start = max(currentStart,0LL);
	    long long end = min(currentEnd,Size);
	    //cout << start << ' ' << end << ':';
	    auto left = lower_bound(sum.begin(), sum.end(),start, [](const pair<long long ,long long >& p, long long  key){ return p.first < key; });
	    auto right = lower_bound(sum.begin(), sum.end(),end, [](const pair<long long ,long long >& p, long long  key){ return p.first < key; });
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