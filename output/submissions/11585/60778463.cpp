#include <iostream>
#include <vector>

using namespace std;

int n;

char str[2000010];
char ptr[1000010];
int fail[1000010];
int cnt;

void preprocessing(char* ptr) {
	fail[0] = 0;
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

void kmp(char* str, char* ptr) {
	int j = 0;
	for (int i = 0; i < 2*n-1;i++) {
		while (j > 0 && str[i] != ptr[j]) { j = fail[j - 1]; }
		if (str[i] == ptr[j]) {
			if (j == n - 1) {
				cnt++;
				j = fail[j];
			}
			else {
				j++;
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		str[n + i] = str[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> ptr[i];
	}
	preprocessing(ptr);
	kmp(str, ptr);
	cout << 1 << '/' << n / cnt;
}