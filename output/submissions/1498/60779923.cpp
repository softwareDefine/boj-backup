#include <iostream>

using namespace std;

string ptr;
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
	cin >> ptr;
	pre(ptr);
	for (int i = 0; i < ptr.size(); i++) {
		if (fail[i]) {
			if ((i+1) % (i + 1 - fail[i]) == 0) {
				cout << (i + 1) << ' ' << (i + 1) / (i + 1 - fail[i]) << '\n';
			}
		}
	}
}