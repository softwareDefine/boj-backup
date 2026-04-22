#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long long n, m,sum;
long long parent[1000010];
long long mmx;

priority_queue <pair<long long,pair<long long, long long>>> vertex;

long long find(long long now) {
	if (parent[now] == now) {
		return now;
	}
	return parent[now] = find(parent[now]);
}

void merge(long long st, long long ed) {
	long long stp = find(st);
	long long edp = find(ed);
	if (stp != edp) {
		if (stp < edp) {
			parent[stp] = edp;
		}
		else {
			parent[edp] = stp;
		}
	}
}

int main()
{
	cin >> n >> m;
	for (long long i = 0; i <= n; i++) {
		parent[i] = i;
	}
	for (long long i = 0; i < m; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		vertex.push({ -c,{a,b} });
	}
	long long szze = vertex.size();
	for (long long i = 0; i < szze; i++) {
		long long value = -vertex.top().first;
		long long start = vertex.top().second.first;
		long long end = vertex.top().second.second;
		if (find(start) != find(end)) {
			merge(start, end);
			sum += value;
			mmx = max(value, mmx);
		}
		vertex.pop();
	}
	cout << sum-mmx;
}
