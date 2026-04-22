#include <iostream>
#include <string>
#include <string.h>

using namespace std;
char a[1000];
int main()
{
	do {
		
		int cnt = 0;
		cin.getline(a,256);
		if (a[0] == '#') {
			break;
		}
		for (int i = 0;i<strlen(a)-1; i++) {
			if (a[i] == 'i' || a[i] == 'e' || a[i] == 'a' || a[i] == 'o' || a[i] == 'u' || a[i] == 'I' || a[i] == 'E' || a[i] == 'A' || a[i] == 'O' || a[i] == 'U') {
				cnt++;
			}
		}
		cout << cnt << '\n';
	} while (1);
}