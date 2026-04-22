#include <iostream>


using namespace std;

string str;
int n;
int cnt;

int main()
{
	cin >> n;
	cin >> str;
	int in = 0;
	for (int i = 0; i < n-1; i++) {
		if (str[i] != str[i + 1]) {
			if (in == 0) {
				cnt++;
				in = 1;
			}
			else {
				in = 0;
			}
		}
	}
	cout << cnt+1;
}