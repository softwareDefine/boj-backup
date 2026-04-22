#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;

int n;
int sum;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		pq.push(a);
	}
	while (1) {
		if (pq.size() == 1) {
			break;
		}
		int smallsum = 0;
		smallsum= pq.top();
		pq.pop();
		smallsum += pq.top();
		sum += smallsum;
		pq.pop();
		pq.push(smallsum);
	}
	cout << sum;
}
