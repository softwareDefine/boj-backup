#include <iostream>

using namespace std;

string a, b, c, d;
long long n;
char one, two, three, four,five,six,seven;
long long x, y, z;
long long cnt1,cnt2;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a == b) {
			cout << "OK" << '\n';
		}
		else {
			cout << "ERROR" << '\n';
		}
	}
	
}