#include <iostream>
#include <algorithm>

using namespace std;

long long l, p;
long long arr[1000];

int main()
{
	cin >> l >> p;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 5; i++) {
		cout <<  arr[i]-l*p << ' ';
	}
}