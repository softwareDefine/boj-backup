#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int 짝수;
int 홀수,n;
int one, two;
int arr[1001001];
ll sum = 0;
vector<int> nnw;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		sum +=arr[i] % 3;
		if (arr[i] == 1) {
			one++;
		}
		else if(arr[i]==2){
			two++;
		}
	}
	if (sum%3) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}