#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char pass[10000];
int n, m;
vector<char> vc;
int used[10000];
int cmp(char a, char b) {
	return a < b;
}

void makepassword(int now, int least, int index) {
	if (now == index) {
		int check=0;
		int check2 = 0;
		for (int j = 0; j < n; j++) {
			if (vc[j] == 'a' || vc[j]=='e' || vc[j] =='o' || vc[j]=='i' || vc[j] == 'u') {
				check = 1;
			}
			else {
				check2++;
			}
		}
		if (check == 1 && check2>=2) {
			for (int j = 0; j < n; j++) {
				cout << vc[j];
			}
			cout << "\n";
		}
		return;
	}
	for (int i = least; i < m;i++) {
		if (used[i]==1) {
			continue;
		}
		used[i] = 1;
		vc.push_back({pass[i]});
		makepassword(now+1,i+1,index);
		vc.pop_back();
		used[i] = 0;
	}
}

int main()
{
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> pass[i];
	}
	sort(pass, pass + m,cmp);
	makepassword(0,0,n);
}