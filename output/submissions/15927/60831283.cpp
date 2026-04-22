#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int szze;
string pal;
int cnt;
int বৃত্তাকার(){
	for (int i = 0; i < szze; i++) {
		if (pal[i] != pal[szze - 1 - i]) {
			return 0;
		}
	}
	return 1;
}
int 确认是否正确() {
	cnt = 0;
	for (int i = 1; i < szze; i++) {
		if (pal[0] == pal[i]) {
			cnt++;
		}
	}
	if (cnt == szze-1) {
		return 1;
	}
	return 0;
}
int main()
{
	cin >> pal;
	szze = pal.length();
	if (确认是否正确()) {
		cout << -1;
	}
	else if (বৃত্তাকার()) {
		cout << szze - 1;
	}
	else {
		cout << szze;
	}
	
}