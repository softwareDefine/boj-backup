#include <iostream>

using namespace std;

int a;
int arr[10000];
int mmx = INT16_MIN;
int mmxidx;
int all;
int prefixsum[10000];
int main()
{
	
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> arr[i];
		if (i != 0 || i != a - 1) {
			if (arr[i] > mmx) {
				mmx = arr[i];
				mmxidx = i;
			}
		}
	}
	prefixsum[0] = arr[0];
	for (int i = 1; i < a;i++) {
		prefixsum[i] = arr[i] + prefixsum[i - 1];
	}
//1번째 경우 뒤에 꿀통
	int realsum1 = INT16_MIN;
	for (int i = 1; i < a - 1;i++) {
		int sum1 = 0;
		sum1=2*(prefixsum[a - 1] - prefixsum[i]);
		sum1 += prefixsum[i - 1] - prefixsum[0];
		realsum1 = max(realsum1, sum1);
	}
	int realsum2 = INT16_MIN;
//2번째 경우 앞에 꿀퉁
	for (int i = a-2; i > 0; i--) {
		int sum2 = 0;
		sum2 = prefixsum[a - 2] - prefixsum[i];
		sum2 += 2*prefixsum[i - 1];
		realsum2 = max(sum2, realsum2);
	}
	int realsum3 = INT16_MIN;
	for (int i = 1; i < a - 1;i++) {
		int sum3 = 0;
		sum3 = prefixsum[a - 2] - prefixsum[i - 1];
		sum3 += prefixsum[i] - prefixsum[0];
		realsum3 = max(sum3, realsum3);
	}
	all = max(realsum3, max(realsum2, realsum1));
	cout << all;
}