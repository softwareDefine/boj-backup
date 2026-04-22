#include <iostream>
#include <string>

using namespace std;

int n;
int a, b, c,x,y,t;
int main()
{
	cin >> a >> x >> b >> y >> t;
	cout << 21 *((t-30<0)?0:t-30)*x + a<< " " << 21 * ((t - 45 < 0) ? 0 : t - 45) * y+b;
}