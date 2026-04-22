#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>

using namespace std;


int n;
double arr[110][2];
int parent[1000100];
double ans;
priority_queue < pair<double, pair<int, int>>> pq;

int find(int now) {
	if (parent[now] == now) {
		return now;
	}
	return parent[now] = find(parent[now]);
}

void merge(int st, int ed) {
	int stp = find(st);
	int edp = find(ed);
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
	cin >> n;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}
			pq.push({ -sqrt(pow(abs(arr[i][0]-arr[j][0]),2)+ pow(abs(arr[i][1] - arr[j][1]),2)),{i,j}});
		}
	}
	for (int i = 0;i<pq.size(); i++) {
		double value = -pq.top().first;
		int start = pq.top().second.first;
		int end = pq.top().second.second;
		if (find(parent[start]) != find(parent[end])) {
			ans += value;
			merge(start, end);
		}
		pq.pop();
	}
	printf("%.100lf", ans);
}