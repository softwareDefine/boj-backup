// a-151.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;
long long a, b, c, d,n;
int main()
{
	cin >> n >> a >> b >> c >> d;
	int i = 0;
	while (n > a*i) {
		i++;
	}
	int j = 0;
	while (n > c *j) {
		j++;
	}
	cout << min(b * i, d *j);
}