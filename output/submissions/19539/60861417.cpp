#include <iostream>
#include <vector>

using namespace std;

int 짝수;
int 홀수,n;
int one, two;
int arr[1001001];
vector<int> nnw;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		arr[i] %= 3;
		if (arr[i] == 1) {
			one++;
		}
		else{
			two++;
		}
	}
	if (((two%2==1)&& (one%2==1))|| one%2 == two%2) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}