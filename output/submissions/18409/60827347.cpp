#include <iostream>
#include <string>

using namespace std;

int n, m;
int suma, sumb;
bool flag;
string str;
int main()
{
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o'|| str[i]=='u') {
			suma++;
		}
	}
	cout << suma;
}