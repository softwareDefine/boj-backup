#include <iostream>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,greater<int>> pq2;
priority_queue<int> pq1;
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (pq1.empty()) {
			pq1.push(a);
		}
		else if (pq1.top() < a) {
			pq2.push(a);
		}
		else {
			pq1.push(a);
		}
		if (pq1.size() < pq2.size()) {
			int tmp = pq2.top();
			pq2.pop();
			pq1.push(tmp);
		}
		else if(pq1.size() > pq2.size()+1) {
			int tmp = pq1.top();
			pq1.pop();
			pq2.push(tmp);
		}
		cout << pq1.top() << '\n';
	}
}