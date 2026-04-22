#include <iostream>

using namespace std;

double x[2000000];
double y[2000000];
int n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		if (i == n ) {
			sum += x[i] * y[1];
			break;
		}
		sum += x[i] * y[i + 1];
	}
	for (int i = 1; i <= n; i++) {
		if (i == n ) {
			sum -= x[1] * y[i];
			break;
		}
		sum -= x[i+1] * y[i];
	}
	printf("%.1lf", abs(sum)/2.0);
} 
