#include <iostream>

using namespace std;

int a,b,c,d,e;
int cnt;

int main()
{
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cout << (a + b + c + d) / 60 << '\n';
	cout << (a + b + c + d) % 60;
}
