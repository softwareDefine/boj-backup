#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> vc;
bool flag = true;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
			if (a % 2 == 0) {
				if (i % 2 == 0) {
					flag = false;
					break;
				}
			}
			else {
				if (i % 2 == 1) {
					flag = false; 
					break;
				}
			}
	}
	if (flag == true) {
		cout << "YES";
	}else{
		cout << "NO";
	}
	
}
