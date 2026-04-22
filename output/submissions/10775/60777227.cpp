#include <iostream>

using namespace std;

int parent[100010];
int g;
int p;
int cnt;
bool  flag;

int find(int now) {
	if (parent[now] == now) {
		return now;
	}
	return parent[now] = find(parent[now]);
}

void merge(int st,int ed) {
	int stp = find(parent[st]);
	int edp = find(parent[ed]);
	if (stp > edp) {
		parent[stp] = edp;
	}
	else {
		parent[edp] = stp;
	}
}


int main()
{
	cin >> g;
	cin >> p;
	for (int i = 1; i <= g; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < p; i++) {
		int q;
		cin >> q;if (find(q) == 0) {
				flag = true;
			}
		if (!flag) {
			
			merge(find(q)-1, q);
			cnt++;
		}
	}
	cout << cnt;
}
