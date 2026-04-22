#include <iostream>
#define LLONG_MAX 9223372036854775807
#define LLONG_MIN (-9223372036854775807 - 1)
using namespace std;
long long n, m;
//첫번째 : 최솟값 , 두번째 : 최댓값
pair<long long,long long> tree[1 << 18];
long long arr[1000000];

pair<long long, long long> maketree(int start, int end, int node) {
	if (start == end) {
		tree[node].first = arr[start];
		tree[node].second = arr[start];
		return {tree[node].first,tree[node].second};
	}
	pair<long long, long long> a = maketree(start, (start + end) / 2, node * 2);
	pair<long long, long long> b = maketree((start+end)/2+1,end,node*2+1);
	if (a.first <= b.first) {
		tree[node].first = a.first;
	}
	else {
		tree[node].first = b.first;
	}
	if (a.second >= b.second) {
		tree[node].second = a.second;
	}
	else {
		tree[node].second = b.second;
	}
	return {tree[node].first,tree[node].second};
}

pair<long long, long long> query(int start, int end, int left, int right, int node) {
	if (left > end  || right < start) {
		return { LLONG_MAX,LLONG_MIN};
	}
	if (left <= start && end <= right) {
		return {tree[node].first, tree[node].second};
	}
	pair<long long,long long> a =query(start, (start + end) / 2, left, right, node * 2);
	pair<long long, long long> b = query((start + end) / 2 + 1, end, left, right, node * 2 + 1);
	pair<long long, long long> ans;
	if (a.first <= b.first) {
		ans.first = a.first;
	}
	else {
		ans.first = b.first;
	}
	if (a.second >= b.second) {
		ans.second = a.second;
	}
	else {
		ans.second = b.second;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	maketree(1,n,1);
	for (int i = 0; i < m; i++) {
		long long a, b;
		cin >> a >> b;
		pair<long long,long long> ans = query(1, n, a, b, 1);
		cout <<ans.first << ' ' << ans.second << '\n';
	}
}
