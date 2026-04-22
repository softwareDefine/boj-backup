#include <iostream>

using namespace std;
typedef struct h {
	int x;
	int y;
	int z;
}h;
h a;
h c;
int main()
{
	cin >> a.x >> a.y >> a.z;
	cin >> c.x >> c.y >> c.z;
	cout << c.x-a.z << ' ' << c.y/a.y<<' ' << c.z-a.x;
}