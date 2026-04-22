#include <iostream>
#include <vector>

using namespace std;

int n;
int getter[1000010];
int cnt,chk;
void factor(int n) {
	for (int i = 2; i <= n; i++) {
		if (getter[i]==1) {
			continue;
		}
		for (int j =  i; j <= n; j += i) {
			if (getter[j]==1) {
				continue;
			}
			getter[j] = 1;
			cnt++;
			if (cnt == chk) {
				cout << j;
				return;
			}
		}
	}
}

int main()
{
	cin >> n >> chk;
	factor(n);
}