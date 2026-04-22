#include <iostream>

using namespace std;

string ptr;
int m;
int fail[1000010];

void pre(string& ptr) {
	int n = ptr.size();
	int j = 0;
	for (int i = 1; i < n; i++) {
		while (j > 0 && ptr[i] != ptr[j]) { j = fail[j - 1]; }
		if (ptr[i] == ptr[j]) {
			fail[i] = ++j;
		}else{
			fail[i] = 0;
		}
	}
}

int main()
{
	cin >> ptr >> m;
	pre(ptr);
	cout << (ptr.size() - fail[ptr.size() - 1])*(m-1) + ptr.size();
}