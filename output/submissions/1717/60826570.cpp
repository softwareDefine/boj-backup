#include <iostream>
using namespace std;

int unionfind[1000000];
int n, m;
int check, a, b;


int find(int now) {
	if (unionfind[now] == now) {
		return now;
	}
	else {
		int un = find(unionfind[now]);
		unionfind[now] = un;
		return un;
	}
}
void merge(int st,int fn) {
	int x = find(st);
	int y = find(fn) ;
	if (x!=y) {
		unionfind[x] = y;
	}
}
void same(int st,int fn) {
	if (find(st) == find(fn)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		unionfind[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> check>> a >> b;
		if (check == 0) {
			merge(a,b);
			continue;
		}
		else {
			same(a,b);
		}
		
	}
}