#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100];
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for(int j=0; j<str.size(); j++) {
			if(str[j] == '.') {
				str.erase(str.begin()+j,str.begin()+j+1);
				break;
			}
		}
		arr[i] = stoi(str);
	}
	for (int i = 1; i < 1000000; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if(((((arr[j]*i/1000) < ((arr[j]+1)*i/1000)) && (((arr[j]+1)*i)%1000 != 0))) || ((arr[j]*i)%1000 == 0) && arr[j]*i <= 10000*i) {
				cnt++;
			}
		}
		if (cnt == n) {
			cout << i;
			return 0;
		}
	}
}