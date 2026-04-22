#include <iostream>
#include <string>

using namespace std;

long long lln[10000];
long long m;

string A = "Messi ";
string B = "Messi Gimossi ";
void messi(int n, int m) {
	if (n == 1) {
		if (A[m - 1] == ' ') {
			cout << "Messi Messi Gimossi";
		}
		else {
			cout << A[m - 1];
		}
		return;
	}
	if (n == 2) {
		if (B[m - 1] == ' ') {
			cout << "Messi Messi Gimossi";
		}
		else {
			cout << B[m - 1];
		}
		return;
	}
	if (lln[n - 1] >= m) {
		messi(n - 1, m);
	}
	else {
		messi(n - 2, m - lln[n - 1]);
	}
}

int main()
{
	cin >> m;
	lln[1] = 6;
	lln[2] = 14;
	int i;
	for (i = 3; i<45; i++) {
		lln[i] = lln[i - 1] + lln[i - 2];
	}
	messi(45, m);
}