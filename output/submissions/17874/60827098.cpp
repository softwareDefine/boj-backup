#include <iostream>

using namespace std;

int n, h, v;

int main()
{
	cin >> n >> h >> v;
	cout <<4*max(h, n - h)* max(v,n-v);
}