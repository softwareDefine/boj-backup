#include <iostream>
#include <string>

using namespace std;

int n, m;
int suma, sumb;
bool flag;
string str;
int main()
{
	cin >> n >> m;
	cout << (((n - (m + 60))>0)?n-(m+60):0) * 3000 + (min(n,m + 60)) * 1500;
}