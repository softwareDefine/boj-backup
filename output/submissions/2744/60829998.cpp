#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int n;
int main()
{
	string a;
	cin >> a;
	for (int i = 0; i < a.length(); i++) {
		if (isupper(a[i])) {
			cout << char(tolower(a[i]));
			
		}
		if (islower(a[i])) {
			cout << char(toupper(a[i]));

		}
	}
}