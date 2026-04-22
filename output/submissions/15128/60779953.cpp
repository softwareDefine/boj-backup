// a-151.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;
long long a, b, c, d;
int main()
{
	cin >> a >> b >> c >> d;
	if ((a*c) % ((b*d)*2)==0) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}