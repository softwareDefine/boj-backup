#include <iostream>

using namespace std;

int sh, sm, ss, eh, em, es;
int allh;
int counthouerminus;
int countminutminus;
int allm;
int alls;
int main()
{
	for (int i = 0; i < 3; i++) {
		cin >> sh >> sm >> ss >> eh >> em >> es;
		alls = 0;
		allm = 0;
		allh = 0;
		counthouerminus = 0;
		countminutminus = 0;
		if (es - ss <0) {
			alls = es - ss + 60;
			countminutminus++;
		}
		else {
			alls = es - ss;
		}
		if (em - (sm + countminutminus) < 0) {
			allm = em - (sm + countminutminus)+60;
			counthouerminus++;
		}
		else {
			allm = em - (sm + countminutminus);
		}
		if (eh - (sh + counthouerminus) < 0) {
			allh = eh - (sh + counthouerminus) + 60;
			counthouerminus++;
		}
		else {
			allh = eh - (sh + counthouerminus);
		}
		cout << allh << ' ' << allm << ' ' << alls << '\n';
	}
}