#include <iostream>
#include <math.h>
#include <string.h>
#include <string>

using namespace std;

int a,b,c,d,e;
int suma,sumb;

int main()
{
	while (1) {
		char str[1010];
		cin.getline(str, 1010);
		if (strcmp(str,"END") == 0) {
			break;
		}
		for (int i = strlen(str) - 1; i >= 0; i--) {
			cout << str[i];
		}
		cout << '\n';
	}
}