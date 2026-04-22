#include <iostream>
#include <string>

using namespace std;

long long k, d, a;
int main()
{
	char str;
	cin >> k >> str >> d >> str >> a;
	if (k + a < d || d ==0){
		cout << "hasu";
	}
	else {
		cout << "gosu";
	}
}