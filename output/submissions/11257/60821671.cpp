#include <iostream>

using namespace std;

long long n;
char one, two, three, four,five,six,seven;
long long x, y, z;
long long cnt1,cnt2;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		int a, b, c;
		cin >> str >> a >> b >> c;
		cout << str << " " << a + b + c << " ";
		if(a >= 11 && b >= 8&& c >= 12 && a+b+c>=55){
			cout << "PASS" << '\n';
		}
		else {
			cout << "FAIL" << '\n';
		}
	}
}