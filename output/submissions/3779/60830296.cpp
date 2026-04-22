#include <iostream>

using namespace std;

string ptr;
int t;
int fail[1000010];

void pre(string& ptr) {
	int n = ptr.size();
	int j = 0;
	for (int i = 1; i < n; i++) {
		while (j > 0 && ptr[i] != ptr[j]) { j = fail[j - 1]; }
		if (ptr[i] == ptr[j]) {
			fail[i] = ++j;
		}
		else {
			fail[i] = 0;
		}
	}
}


int main()
{
	int cnt = 0;
	while (1) {
		int n;
		cin >> n;

		if (n == 0) {
			break;
		}
		fill(fail, fail + 1000010,0);
		cin >> ptr;
		pre(ptr);
		cout << "Test case #" << ++cnt << '\n';
		for (int i = 0; i < ptr.size(); i++) {
			if (fail[i]) {
				if ((i + 1) % (i + 1 - fail[i]) == 0) {
					cout << (i + 1) << ' ' << (i + 1) / (i + 1 - fail[i]) << '\n';
				}
			}
		}
		cout << '\n';
	}
	
}