#include <iostream>

using namespace std;

int a, b, c;
char arr[1000][1000];
int main()
{
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < a; i++){
		for (int j = b - 1; j >= 0; j--) {
			cout << arr[i][j];
		}
		cout << '\n';
	}			
}