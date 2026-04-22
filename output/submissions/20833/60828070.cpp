#include <iostream>
#include <cmath>

using namespace std;

int n;
long long a, b, c,x,y,t;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		t += pow(i, 3);
	}
	cout << t;
}