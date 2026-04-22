#include <iostream>

using namespace std;
int x, y, w, h;
int main()
{
	cin >> x >> y >> w >> h;
	cout << min(min(w - x, h - y), min(x, y));
}