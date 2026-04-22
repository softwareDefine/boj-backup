#include <iostream>

using namespace std;


bool s[6600][6600];
int n;

void star(int now,int x, int y){
	if (now == 1) {
		if (!s[y][x]) {
			s[y][x] = true;
		}
		return;
	}
	if (now == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i==1 && j==1) 
				{
					continue;
				}
				s[y + i][x + j] = true;
			}
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (!(i == 1 && j == 1))
					star(now / 3, x + j* (now / 3), y + i * (now / 3));
			}
		}
	}
}

int main()
{
	cin >> n;
	star(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!s[i][j]) {
				cout << ' ';
			}
			else {
				cout << '*';
			}
		}
		cout << '\n';
	}
}