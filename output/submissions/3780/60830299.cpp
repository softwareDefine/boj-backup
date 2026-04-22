#include <iostream>
#include <utility>

using namespace std;

int parent[1000010];
int szze[1000010];
int t;
int n;

int find(int now) {
	if (parent[now] == now) {
		return now;
	}
	int get = find(parent[now]);
	szze[now] += szze[parent[now]];
	return parent[now] = get;
}

void merge(int start,int end){
		parent[start] = end;
		szze[start] = abs(start-end)%1000;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> t;
	while (t--) {
		for (int i = 0; i < 1000010; i++) {
			szze[i] = 0;
			parent[i] = i;
		}
		cin >> n;
		char a;
		int b, c;
		while (1) {
			cin >> a;
			if (a == 'O') {
				break;
			}
			if (a == 'I') {
				cin >> b >> c;
				merge(b, c);
			}
			else {
				cin >> b;
				find(b);
				cout << szze[b] << '\n';
			}
		}
	}
}