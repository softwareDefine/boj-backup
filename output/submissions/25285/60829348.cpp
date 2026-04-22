#include <iostream>

using namespace std;

long long sum;
int t;
int main()
{
	cin >> t;
	while (t--) {
		int cm, kg;
		int getter = 6;
		cin >> cm >> kg;
		double bmi = (double)kg / ((cm/100.0)*(cm /100.0));
		if (cm >= 204) {
			getter = 4;
		}
		else if (cm >= 161) {
			if (bmi < 25.0 && bmi>= 20.0) {
				getter = 1;
			}
			else if ((bmi >= 18.5 && bmi < 20.0) || (bmi >= 25.0 && bmi < 30.0)) {
				getter = 2;
			}
			else if ((bmi >= 16.0 && bmi < 18.5) || (bmi >= 30.0 && bmi < 35.0)) {
				getter = 3;
			}
			else if (bmi < 16.0 || bmi >= 35.0) {
				getter = 4;
			}
		}
		else if (cm >= 159) {
			if (bmi >= 16.0 && bmi<35.0) {
				getter = 3;
			}
			else {
				getter = 4;
			}
		}
		else if (cm >= 146) {
			getter = 4;
		}
		else if (cm >= 140.1) {
			getter = 5;
		}
		else {
			getter = 6;
		}
		cout << getter << '\n';
	}
}